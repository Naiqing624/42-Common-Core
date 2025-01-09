/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:36:10 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:31:33 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_victory_game(t_game *game)
{
	ft_printf("Movement: %d\n", ++game->movement);
	ft_printf("Congratulation!\n");
	ft_free_all_memery(game);
	exit (EXIT_SUCCESS);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movement: %d\n", game->movement);
	ft_printf("You closed the game\n");
	ft_free_all_memery(game);
	exit(0);
	return (0);
}
