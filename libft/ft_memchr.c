#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;

    ptr = s;
    while (n--)
    {
        if (*ptr == (unsigned char) c)
        {
            return ((void *)ptr);
        }
        ptr++;
    }
    return (NULL);
}

int main(void)
{
    const char str[] = "Hello";
    char *result;

    result = ft_memchr(str, 'l', 6);
    printf("%ld\n", result - str);
    return (0);
}