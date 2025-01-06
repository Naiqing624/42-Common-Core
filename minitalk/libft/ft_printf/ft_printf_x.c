/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:53 by nacao             #+#    #+#             */
/*   Updated: 2024/11/07 17:23:56 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned int i)
{
	int		count;

	count = 0;
	while (i != 0)
	{
		i /= 16;
		count++;
	}
	return (count);
}

void	ft_printhex(unsigned int i, const char format)
{
	if (i >= 16)
	{
		ft_printhex(i / 16, format);
		ft_printhex(i % 16, format);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
		{
			if (format == 'x')
				ft_putchar(i - 10 + 'a');
			if (format == 'X')
				ft_putchar(i - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int i, const char format)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_printhex(i, format);
	return (ft_counthex(i));
}
