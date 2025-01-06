/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:19:57 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 08:23:02 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		return (NULL);
	}
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}
/*
int main() {
    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Free the allocated memory
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}*/
