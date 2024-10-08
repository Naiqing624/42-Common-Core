#include "libft.h"

size_t  ft_strlcat(char *dest, char *src, size_t size)
{
    size_t  dest_len;
    size_t  src_len;
    size_t  i;

    dest_len = ft_strlen(dest);
    src_len = ft_strlen (src);
    if (size <= dest_len)
    {
        return (size + src_len);
    }
    i = 0;
    while (src[i] && (dest_len + i) < (size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len] = '\0';
    return (dest_len + src_len);
}