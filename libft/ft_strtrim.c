#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *trim;

    end = ft_strlen(s1);
    start = 0;
    if (!s1)
    {
        return (NULL);
    }
    if (!set)
    {
        return (ft_strdup(s1));
    }
    while (s1[start] && ft_strchr(set, s1[start]))
    {
        start++;
    }
    while (s1[end] && ft_strchr(set, s1[end - 1]))
    {
        end--;
    }
    trim = ft_substr(s1, start, end - start);
    return (trim);
}