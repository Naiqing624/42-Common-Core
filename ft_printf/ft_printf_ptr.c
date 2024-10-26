#include "ft_printf.h"
#include "libft/libft.h"
#include <stdint.h>

int		ft_ptr_len(uintptr_t num)
{
    int len;

    len = 0;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void	ft_put_ptr(uintptr_t num)
{
    if (num >= 16)
    {
        ft_put_ptr(num / 16);
        ft_put_ptr(num % 16);
    }
    else
    {
        if (num <= 9)
            ft_putchar_fd((num + '0'), 1);
        else
            ft_putchar_fd((num - 10 + 'a'), 1);
    }
}

int		ft_print_ptr(unsigned long long ptr)
{
    int print_length;

    if (ptr == 0)
        return (write(1, "(nil)", 5));
    print_length = write(1, "0x", 2);
    ft_put_ptr(ptr);
    print_length += ft_ptr_len(ptr);
    return (print_length);
}