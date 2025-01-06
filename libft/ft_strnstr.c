/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:19:17 by nacao             #+#    #+#             */
/*   Updated: 2024/10/25 10:19:38 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (len > big_len)
		len = big_len;
	while (*big && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
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
