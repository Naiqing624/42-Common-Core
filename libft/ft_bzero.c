#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
  /*unsigned char *ptr;

    ptr = (unsigned char *)s;
    while (n > 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }*/
    ft_menset(s, 0, n);
}

