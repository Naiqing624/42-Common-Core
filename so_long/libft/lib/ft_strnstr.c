/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:06:11 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:06:11 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	find_size;

	i = 0;
	find_size = ft_strlen(to_find);
	if (!find_size)
		return ((char *) str);
	if (!size)
		return (0);
	while (str[i] && i + find_size <= size)
	{
		if (!ft_strncmp(&str[i], to_find, find_size))
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}
