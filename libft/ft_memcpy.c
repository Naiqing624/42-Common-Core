#include "libft.h"

void    *ft_memcpy(void *dest, void *src, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;

    if (!dest || !src)
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

int main(void)
{
    char    ptr1[6] = "hello";
    char    ptr2[6] = "world";
    ft_memcpy(ptr1, ptr2, 6);
    printf("%s\n", ptr1);
    return (0);
}