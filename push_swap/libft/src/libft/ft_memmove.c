/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:03:40 by nacao             #+#    #+#             */
/*   Updated: 2024/10/25 10:06:12 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d && d < s + len)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
			*(d++) = *(s++);
	}
	return (dest);
}
/*
int main(void)
{
    char    str[] = "hello, world!";

    ft_memmove(str, str + 7, 6);
    str[6] = '\0';
    printf("%s", str);

}*/
