#include "get_next_line.h"

static int		read_buffer(int fd, char **stash, char *buffer)
{
    char *tmp;
    int byte;

    ft_bzero(buffer, BUFFER_SIZE + 1);
    byte = read(fd, buffer, BUFFER_SIZE);
    if (byte < 0)
    {
        free(*stash);
        *stash = NULL;
        return (-1);
    }
    if (byte == 0)
        return (0);

    tmp = ft_strjoin(*stash, buffer);
    if (!tmp)
        return (-1);

    free(*stash);
    *stash = tmp;
    return (byte);
}

static int		remove_result(char **stash)
{
    char *tmp;
    char *n1;

    n1 = ft_strchr(*stash, '\n');
    if (!n1)
    {
        free(*stash);
        *stash = NULL;
        return (0);
    }
    tmp = ft_strdup(n1 + 1);
    if (!tmp)
        return (-1);
    
    free(*stash);
    *stash = tmp;

    if (**stash == '\0')
    {
        free(*stash);
        *stash = NULL;
    }

    return (1);
}

static void		get_result(char **stash, char **result)
{
    char *n1;
    size_t len;
    size_t i;

    n1 = ft_strchr(*stash, '\n');
    len = ft_strlen(*stash);
    if (n1)
        len = n1 - *stash + 1;

    *result = (char *)malloc((len + 1) * sizeof(char));
    if (!*result)
        return;

    i = 0;
    while (i < len)
    {
        (*result)[i] = (*stash)[i];
        i++;
    }
    (*result)[i] = '\0';
}

char		*get_next_line(int fd)
{
    static char *stash;
    char *result = NULL;
    char *buffer;
    int byte;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (!stash)
        stash = ft_strdup("");

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);

    byte = 1;
    while (ft_strchr(stash, '\n') == NULL && byte > 0)
        byte = read_buffer(fd, &stash, buffer);

    free(buffer);

    if (byte < 0 || !stash || ft_strlen(stash) == 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }

    get_result(&stash, &result);
    if (!result)
        return (NULL);

    if (remove_result(&stash) == -1)
    {
        free(result);
        return (NULL);
    }

    return (result);
}