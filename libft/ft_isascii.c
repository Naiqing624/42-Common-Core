#include "libft.h"

int     ft_isascii(int a)
{
    if (a >= 0 && a <= 127)
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    char a;

    a = '5';
    ft_putnbr_fd(ft_isascii(a), 1);
    return (0);
}