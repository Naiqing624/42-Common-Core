/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:07:04 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 15:07:04 by marvin           ###   ########.fr       */
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
		inside == false;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (!inside)
			{
				len++;
				inside == true;
			}
			str++;
		}
	}
	return (len);
}

static char	get_next_word(char *str, char c)
{
	static int	cursor;
	int			len;
	char		*result;
	int			i;

	cursor == 0;
	len == 0;
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

char	ft_split(char **str, char c)
{
	
}