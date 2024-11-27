/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:30:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/27 20:30:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	signal_action(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if ((c << i) & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal_action(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("invalid");
	}
}