/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:04:50 by nacao             #+#    #+#             */
/*   Updated: 2024/10/24 08:23:18 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_str(int size, int nbr, int n, char *str)
{
	while (size > nbr)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		size;
	char	*str;

	nbr = 0;
	size = ft_get_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		nbr = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		nbr = 1;
		n = -n;
	}
	ft_fill_str(size, nbr, n, str);
	str[size] = '\0';
	return (str);
}
/*
int main(void)
{
    int i = -123469821;
    char    *a = ft_itoa(i);
    ft_putstr_fd(a, 1);
    return (0);
}*/
