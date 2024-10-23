/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:23:33 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 08:28:45 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	actuel_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	actuel_len = s_len - start;
	if (actuel_len > len)
		actuel_len = len;
	substr = (char *)malloc((actuel_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, actuel_len + 1);
	return (substr);
}
/*
int main(void)
{
    char *str1 = "Hello";
    char *substr = ft_substr(str1, 2, 3);
    printf("%s", substr);
}*/
