/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
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
		return (ft_putpointer(va_arg(args, unsigned long long int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
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
/*
#include <stdio.h> 

int main()
{
    // 测试字符输出
    ft_printf("Character: %c\n", 'A');
    printf("Expected: Character: %c\n", 'A');

    // 测试字符串输出
    ft_printf("String: %s\n", "Hello, World!");
    printf("Expected: String: %s\n", "Hello, World!");

    // 测试指针输出
    int num = 42;
    ft_printf("Pointer: %p\n", (void *)&num);
    printf("Expected: Pointer: %p\n", (void *)&num);

    // 测试十进制整数输出
    ft_printf("Integer (d): %d\n", 12345);
    printf("Expected: Integer (d): %d\n", 12345);

    ft_printf("Integer (i): %i\n", -6789);
    printf("Expected: Integer (i): %i\n", -6789);

    // 测试无符号整数输出
    ft_printf("Unsigned integer: %u\n", 4294967295U);
    printf("Expected: Unsigned integer: %u\n", 4294967295U);

    // 测试十六进制小写输出
    ft_printf("Hexadecimal (x): %x\n", 255);
    printf("Expected: Hexadecimal (x): %x\n", 255);

    // 测试十六进制大写输出
    ft_printf("Hexadecimal (X): %X\n", 255);
    printf("Expected: Hexadecimal (X): %X\n", 255);

    // 测试百分号输出
    ft_printf("Percent sign: %%\n");
    printf("Expected: Percent sign: %%\n");

    return 0;
}*/
