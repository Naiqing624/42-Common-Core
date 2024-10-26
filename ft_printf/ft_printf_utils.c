#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

int		ft_printstr(char *str)
{
    if (!str)
        return (write(1, "(null)", 6));
    return (write(1, str, ft_strlen(str)));
}

int		ft_printnbr(int n)
{
    char *num;
    int len;

    num = ft_itoa(n);
    if (!num)
        return (0);
    len = ft_printstr(num);
    free(num);
    return (len);
}

int		ft_printpercent(void)
{
    return (write(1, "%", 1));
}