#include "ft_printf.h"
#include "libft.h"

int		ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	    ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}

int main(void)
{
    unsigned int num1 = 42;
    unsigned int num2 = 255;
    unsigned int num3 = 0;
    unsigned int num4 = 4294967295;  // Valeur maximale pour un unsigned int

    printf("Testing ft_print_hex with 'x' format:\n");
    printf("Expected: 2a | Actual: ");
    ft_print_hex(num1, 'x');
    printf("\n");

    printf("Expected: ff | Actual: ");
    ft_print_hex(num2, 'x');
    printf("\n");

    printf("Expected: 0 | Actual: ");
    ft_print_hex(num3, 'x');
    printf("\n");

    printf("Expected: ffffffff | Actual: ");
    ft_print_hex(num4, 'x');
    printf("\n");

    printf("\nTesting ft_print_hex with 'X' format:\n");
    printf("Expected: 2A | Actual: ");
    ft_print_hex(num1, 'X');
    printf("\n");

    printf("Expected: FF | Actual: ");
    ft_print_hex(num2, 'X');
    printf("\n");

    printf("Expected: 0 | Actual: ");
    ft_print_hex(num3, 'X');
    printf("\n");

    printf("Expected: FFFFFFFF | Actual: ");
    ft_print_hex(num4, 'X');
    printf("\n");

    return 0;
}