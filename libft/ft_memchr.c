/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:58:00 by nacao             #+#    #+#             */
/*   Updated: 2024/10/22 11:07:04 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char str[] = "Hello";
    char *result;

    result = ft_memchr(str, 'l', 6);
    printf("%s\n", result);
    return (0);
}*/
