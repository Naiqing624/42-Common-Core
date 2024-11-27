/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:30:41 by marvin            #+#    #+#             */
/*   Updated: 2024/11/27 20:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Handles SIGUSR1 and SIGUSR2 signals by shifting 
// and ORing the bits of a character
// Counter for the number of bits received
// Character being built from the received bits
// Shift the character left and set the least
// significant bit to 1 if the signal is SIGUSR1;
// otherwise, shift the character left and set the least significant bit to 0
// If 8 bits have been received, print the
// character and reset the counter and character

void	handler(int sig)
{
	char	c;
	static int	i;

	if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	else if (sig == SIGUSR2)
		c = c << 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID is %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}