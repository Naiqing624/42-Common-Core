#include "libft.h"

size_t  ft_strlcpy(char *dest, char *src, size_t dstsize)
{
    size_t  src_len;
    size_t  i;

    src_len = ft_strlen(src);
    if (dstsize == 0)
    {
        return (src_len);
    }
    i = 0;
    while (src[i] && i < dstsize - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (src_len);
}