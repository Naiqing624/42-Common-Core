/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:36:56 by nacao             #+#    #+#             */
/*   Updated: 2024/10/22 09:46:24 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a < 127)
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char	str;

	str = '8';
	if (ft_isprint(str))
	{
		printf("printable\n");
	}
	else
	{
		printf("not printable\n");
	}
	return (0);
}*/
