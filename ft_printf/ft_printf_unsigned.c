/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:39:13 by nacao             #+#    #+#             */
/*   Updated: 2024/11/07 13:39:20 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size(unsigned int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		size;

	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (size > 0)
	{
		str[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*str;

	str = ft_utoa(n);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}
/*
#include <stdio.h>

int main()
{
	ft_putunsigned(0); // 输出：0
	write(1, "\n", 1);
	ft_putunsigned(42); // 输出：42
	write(1, "\n", 1);
	ft_putunsigned(4294967295); // 输出：4294967295
	write(1, "\n", 1);
	return 0;
}*/
