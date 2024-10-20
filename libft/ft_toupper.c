#include "libft.h"

int     ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
    }
    return (c);
}
/*
int main(void)
{
    char c;

    c = 'a';
    c = ft_toupper(c);
    ft_putchar_fd(c, 1);
}*/