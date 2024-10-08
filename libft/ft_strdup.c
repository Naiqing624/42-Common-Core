#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *dup;
    size_t  len;

    len = ft_strlen(s1);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
    {
        return (NULL);
    }
    ft_strlcpy(dup, s1, len + 1);
    return (dup);
}