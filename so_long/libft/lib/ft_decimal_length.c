/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:11:14 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:11:14 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_decimal_length(long int nbr)
{
	int	length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr /= 10;
		length++;
	}
	return (length);
}
