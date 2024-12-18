/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:15:27 by nacao             #+#    #+#             */
/*   Updated: 2024/10/25 10:09:33 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen (src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
int main(void)
{
	char str1[20] = "hello";  // 为 str1 分配 20 个字符的缓冲区
    char *str2 = "world";
    size_t result;

    // 调用 ft_strlcat 函数
    result = ft_strlcat(str1, str2, sizeof(str1));  // 传入缓冲区大小
    printf("Result length: %zu\n", result);
    printf("Concatenated string: %s\n", str1);
    return (0);
}*/
