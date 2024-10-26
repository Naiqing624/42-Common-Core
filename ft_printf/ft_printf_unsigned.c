#include "ft_printf.h"
#include <stdlib.h>

int		ft_num_len(unsigned int num)
{
    int len;

    len = 0;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        len++;
        num = num / 10;
    }
    return (len);
}

char	*ft_uitoa(unsigned int n)
{
    char *num;
    int len;

    len = ft_num_len(n);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (!num)
        return (NULL);
    num[len] = '\0';
    if (n == 0)
        num[0] = '0';
    while (n != 0)
    {
        num[--len] = n % 10 + '0';
        n = n / 10;
    }
    return (num);
}

int		ft_print_unsigned(unsigned int n)
{
    int print_length;
    char *num;

    num = ft_uitoa(n);
    if (!num)
        return (0);
    print_length = ft_printstr(num);
    free(num);
    return (print_length);
}