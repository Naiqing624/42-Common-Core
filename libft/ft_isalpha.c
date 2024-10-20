#include "libft.h"

int ft_isalpha(int a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    char a;
    
    a = 'q';
    a = ft_isalpha(a);
    ft_putnbr_fd(a, 1);
}