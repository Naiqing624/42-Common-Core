/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:57:41 by nacao             #+#    #+#             */
/*   Updated: 2024/10/22 09:00:35 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z')
		|| (a >= 'A' && a <= 'Z'))
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
    int i;
    
    i = '5';
    i = ft_isalnum(i);
    ft_putnbr_fd(i, 1);
}*/
