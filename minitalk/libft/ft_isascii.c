/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:35:10 by nacao             #+#    #+#             */
/*   Updated: 2024/10/22 09:36:16 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
    char a;

    a = '5';
    ft_putnbr_fd(ft_isascii(a), 1);
    return (0);
}*/
