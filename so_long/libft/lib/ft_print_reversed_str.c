/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reversed_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:08:36 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:08:36 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_reversed_str(char *str)
{
	int	i;
	int	bytes;

	bytes = ft_strlen(str);
	i = bytes - 1;
	while (i >= 0)
		write(1, &str[i--], sizeof(char) * 1);
	return (bytes);
}
