/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:08:52 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:08:52 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *) dest;
	src_ptr = (const char *) src;
	if (dest > src)
	{
		while (length > 0)
		{
			length--;
			dest_ptr[length] = src_ptr[length];
		}
	}
	else
		ft_memcpy(dest, src, length);
	return (dest);
}
