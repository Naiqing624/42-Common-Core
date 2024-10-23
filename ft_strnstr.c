/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:19:17 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 08:17:33 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (*little == '\0')
	{
		return ((char *)big);
	}
	n = ft_strlen(little);
	while (*big && len >= n)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int main(void)
{
    char str1[] = "hello, world";
    char str2[] = "ello";

    printf("%s", ft_strnstr(str1, str2, 10));
    return(0);
}*/
