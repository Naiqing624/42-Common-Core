/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:56:03 by nacao             #+#    #+#             */
/*   Updated: 2024/10/25 10:37:00 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
		{
			in_substring = 0;
		}
		s++;
	}
	return (count);
}

static	char	*word_dup(char const *s, size_t start, size_t finish)
{
	char	*words;
	size_t	len;

	len = finish - start;
	words = (char *)malloc((len + 1) * sizeof(char));
	if (!words)
	{
		return (NULL);
	}
	ft_memcpy(words, s + start, len);
	words[len] = '\0';
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	finish;
	size_t	words;
	size_t	i;

	words = count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		finish = start;
		while (s[finish] && s[finish] != c)
			finish++;
		split[i] = word_dup(s, start, finish);
		start = finish;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int main(void)
{
    char    *str = "hello hello world";
    int i = 0;
    char **result = ft_split(str, ' ');
    while (result[i] != NULL)
    {
        printf("result[%d]: %s\n", i, result[i]);
        free(result[i]);  
        i++;
    }
    free(result); 
    return (0);
}*/
