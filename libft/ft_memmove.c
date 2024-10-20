#include "libft.h"

void    *ft_memmove(void *dest, void *src, size_t len)
{
    unsigned char   *d;
    unsigned char   *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (d < s)
    {
        while (len--)
        {
            *d++ = *s++;
        }
    }
    else
    {
        d += len;
        s += len;
        while (len--)
        {
            *(--d) = *(--s);
        }
    }
    return (dest);
}

int main(void)
{
    char    str[] = "hello, world!";

    /*ft_memmove(str + 7, str, 5);
    printf("%s\n", str);*/
    ft_memmove(str, str + 7, 6);
    str[6] = '\0';
    printf("%s", str);

}