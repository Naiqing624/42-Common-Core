#include "get_next_line.h"

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *ptr;
    ptr = (unsigned char *)s;

    while (n >= 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }
}

size_t  ft_strlen(const char *str)
{
    size_t  len;

    while(*str)
    {
        len++;
    }
    return (len);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    size_t  total_len;
    int i;
    char    *str;

    if (!s1 || !s2)
    {
        return (NULL);
    }
    total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
    str = (char *)malloc(total_len * sizeof(char));
    if (!str)
    {
        return (NULL);
    }
    i = 0;
    while (*s1)
    {
        str[i] = *s1;
        i++;
        s1++;
    }
    while (*s2)
    {
        str[i] = *s2;
        i++;
        s2++;
    }
    str[i] = '\0';
    return (str);
}