/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:07:30 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:07:30 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sum;

	sum = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		if (n == -2147483648)
		{
			n--;
			sum = 1;
		}
	}
	if (n < 10)
		ft_putchar_fd(n + '0' + sum, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10 + sum, fd);
	}
}
