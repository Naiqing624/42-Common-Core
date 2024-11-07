/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:55:35 by marvin            #+#    #+#             */
/*   Updated: 2024/11/03 14:55:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (0);
	else if (format == 'X')
		return (0);
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	return_len;
	size_t	i;

	if (!format)
		return (1);
	i = 0;
	return_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			return_len += ft_printf_args(format[i + 1], args);
			i++;
		}
		else
			return_len += ft_putchar(format[i]);
		i++;
	}
	return (return_len);
}

#include <stdio.h> 

int main()
{
    ft_printf("Character: %c\n", 'A');
    printf("Expected: Character: %c\n", 'A');

    ft_printf("String: %s\n", "Hello, World!");
    printf("Expected: String: %s\n", "Hello, World!");

	int num = 42;
    ft_printf("Pointer: %p\n", (void *)&num);
    printf("Expected: Pointer: %p\n", (void *)&num);

    ft_printf("Integer: %d\n", 12345);
    printf("Expected: Integer: %d\n", 12345);

    ft_printf("Signed integer: %i\n", -9876);
    printf("Expected: Signed integer: %i\n", -9876);

    ft_printf("Unsigned integer: %u\n", 4294967295);
    printf("Expected: Unsigned integer: %ld\n", 4294967295);

    ft_printf("Percent sign: %%\n");
    printf("Expected: Percent sign: %%\n");

    return 0;
}
