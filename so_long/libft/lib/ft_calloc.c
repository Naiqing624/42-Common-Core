/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:11:33 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:11:33 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr_elements, size_t element_size)
{
	void	*ptr;

	ptr = malloc(nbr_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nbr_elements * element_size);
	return (ptr);
}
