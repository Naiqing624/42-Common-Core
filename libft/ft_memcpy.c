#include "libft.h"

void    *ft_memcpy(void *dest, void *src, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;

    if (!dest && !src)
    {
        return (NULL);
    }
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    while (n > 0)
    {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return (dest);
}