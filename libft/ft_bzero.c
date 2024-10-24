/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:52:37 by nacao             #+#    #+#             */
/*   Updated: 2024/10/22 10:00:33 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
/*
void    ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int main(void)
{
  char str[] = "hello";
  ft_bzero(str, 3);
  printf("%s", str);
  printf("ASCII values after bzero:\n");
  for (int i = 0; i < 5; i++)
    {
        printf("str[%d] = %d\n", i, str[i]);
    }
  return (0);
}*/
