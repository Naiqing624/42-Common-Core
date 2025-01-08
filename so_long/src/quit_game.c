/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:36:10 by nacao             #+#    #+#             */
/*   Updated: 2025/01/08 17:10:36 by nacao            ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}