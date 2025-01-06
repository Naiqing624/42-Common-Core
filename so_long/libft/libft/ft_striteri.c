/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:23:33 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 09:40:36 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void to_uppercase(unsigned int index, char *c)
{
    (void)index;
    if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - ('a' - 'A');
    }
}

int main(void)
{
    char str[] = "hello, world!";
    ft_striteri(str, to_uppercase);
    printf("%s\n", str); // 输出：HELLO, WORLD!
    return 0;
}*/
