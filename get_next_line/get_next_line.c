#include "get_next_line.h"

static int  read_buffer1(int fd, char **stash, char *buffer)
{
    char    *tmp;
    int byte;

    ft_bzero(buffer, BUFFER_SIZE + 1);
    byte = read(fd, buffer, BUFFER_SIZE);
    if (byte < 0 || buffer == NULL)
    {
        free(*stash);
        *stash = NULL;
        return (-1);
    }
    if (byte == 0)
    {
        return (0);
    }
    tmp = ft_strjoin (*stash, buffer);
    free(*stash);
    *stash = tmp;
    return (byte);
}

static int  remove_result(char **stash)
{
    char    *tmp;
    char    *n1;
    size_t  i;
    size_t  j;

    n1 = ft_strchr(*stash, '\n');
    if (!n1)
    {
        free(*stash);
        *stash = NULL;
        return ;
    }
    tmp = malloc ((ft_strlen(n1 + 1) + 1) * sizeof(char));
    i = 0;
    j = ft_strlen(*stash) - ft_strlen(n1) + 1;
    while (j < ft_strlen(*stash))
    {
        tmp[i++] = (*stash)[j++];
    }
    tmp[i] = '\0';
    free(*stash);
    *stash = tmp;
    if (**stash == '\0')
    {
        free(*stash);
        *stash = NULL;
    }
}

static void get_result(char **stash, char **result)
{
    char    *n1;
    size_t  len;
    size_t  i;

    n1 = ft_strchr(*stash , '\n');
    len = ft_strlen(*stash) - ft_strlen(n1) + 2;
    *result = (char *)malloc(len + sizeof(char));
    if (!result)
    {
        return ;
    }
    i = 0;
    while (i < len - 1)
    {
        (*result)[i] = (*stash)[i];
        i++;
    }
    (*result)[i] = '\0';
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *result;
    char    *buffer;
    int byte;

    if (fd < 0 || BUFFER_SIZE < 0)
    {
        return (NULL);
    }
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    byte = 1;
    while (ft_strchr(*stash, '\n') == NULL && byte > 0)
    {
        byte = read_buffer1(fd, *stash, buffer);
    }
    free(buffer);
    if (byte < 0)
    {
        return (NULL);
    }
    if (ft_strlen(stash) == 0)
    {
        return (NULL);
    }
    get_result(&stash, &result);
    remove_result(&stash);
    return (result);
}