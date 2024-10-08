#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    size_t  actuel_len;
    char    *substr;

    if (!s)
    {
        return (NULL);
    }
    s_len = ft_strlen(s);
    if (start > s_len)
    {
        return (ft_strdup(""));
    }
    actuel_len = s_len - start;
    if (actuel_len > len)
    {
        actuel_len = len;
    }
    substr = (char *)malloc((actuel_len + 1) * sizeof(char));
    if (!substr)
    {
        return (NULL);
    }
    ft_strlcpy(substr, s + start, actuel_len + 1);
    return (substr);
}