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
		return (ft_putchar(va_arg(args, char *)));
	else if (format == 'p')
		return (0);
	else if (format == 'd' || format == 'i')
		return (0);
	else if (format == 'u')
		return (0);
	else if (format == 'x')
		return (0);
	else if (format == 'X')
		return (0);
	else if (format == '%')
		return (ft_putchar('%'));
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

int main()
{
	printf ("printf Characters: %c %c \n", 'a', 65);

	ft_printf ("ft_printf Characters: %c %c \n", 'a', 65);
	return 0;
}