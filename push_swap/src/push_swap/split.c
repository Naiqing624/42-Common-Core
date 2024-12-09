/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:07:04 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 10:54:36 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_string(char *str, char c)
{
	int		len;
	bool	inside;

	len = 0;
	while (*str)
	{
		inside = false;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (!inside)
			{
				len++;
				inside = true;
			}
			str++;
		}
	}
	return (len);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	int			len;
	char		*result;
	int			i;

	len = 0;
	while (str[cursor] == c)
		cursor++;
	while (str[cursor + len] != c && str[cursor + len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (str[cursor] != c && str[cursor])
		result[i++] = str[cursor++];
	result[i] = '\0';
	return (result);
}

char	**ft_ssplit(char *str, char c)
{
	char	**result;
	int		count;
	int		i;

	count = count_string(str, c);
	result = malloc(sizeof(char *) * (count + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (count-- > 0)
	{
		if (i == 0)
		{
			result[i] = (char *)malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
		}
		result[i++] = get_next_word(str, c);
	}
	result[i] = NULL;
	return (result);
}

/*
int	main(void)
{
	char	input[] = ",Hello,world,Push,Swap";
	char	delimiter = ',';
	char	**result = ft_ssplit(input, delimiter);
	int		i;

	i = 0;
	while (result[i])
	{
		printf("%s", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/