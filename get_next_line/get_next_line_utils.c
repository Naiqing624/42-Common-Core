#include "get_next_line.h"

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *ptr;
    ptr = (unsigned char *)s;

    while (n > 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }
}

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while(*str++)
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
    size_t total_len;
    char *str;
    size_t i;
    size_t j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    
    total_len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc((total_len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }

    j = 0;
    while (s2[j])
    {
        str[i++] = s2[j++];
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strdup(const char *s)
{
    size_t len = 0;
    char *dup;
    
    while (s[len])
        len++;
    
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    
    dup[len] = '\0';
    
    return (dup);
}