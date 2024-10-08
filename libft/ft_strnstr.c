#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  n;

    if (*little == '\0')
    {
        return ((char *)big);
    }
    n = ft_strlen(little);
    while (*big && len >= n)
    {
        if (*big == *little && ft_strncmp(big, little, n) == 0)
        {
            return ((char *)big);
        }
        big++;
        len--;
    }
    return (NULL);
}