#include "libft.h"

int ft_isdigit(int a)
{
    if (a >= '0' && a <= '9')
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    int i = '8';

    if (ft_isdigit(i))
    {
        ft_putchar_fd(i, 1);
        ft_putchar_fd('\n', 1);
        return (0);
        //ft_putendl_fd();
    }
    else
    {
        printf("erreur\n");
    }
    return (1);
}