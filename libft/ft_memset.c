#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;

    ptr = (unsigned char *)b;
    while (len > 0)
    {
        *ptr = c;
        ptr++;
        len--;
    }
    return (b);
}

int main(void)
{
    char    str[] = "hello";
    printf("%s\n", (char *)ft_memset(str, 'b', 2));
    return (0);
}