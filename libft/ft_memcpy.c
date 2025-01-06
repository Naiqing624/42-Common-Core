/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:00:59 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 10:49:21 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
/*
int main(void)
{
    char    ptr1[6] = "hello";
    char    ptr2[6] = "world";
    ft_memcpy(ptr1, ptr2, 6);
    printf("%s\n", ptr1);
    return (0);
}*/
