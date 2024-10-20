#include "libft.h"

int     ft_tolower(int c)
{
    if (c <= 'A' && c >= 'Z')
    {
        c += 32;
    }
    return (c);
}

/*int main(void)
{
    char a;

    a = 'A';
    a = ft_tolower(a);
    ft_putchar_fd(a, 1);
}*/