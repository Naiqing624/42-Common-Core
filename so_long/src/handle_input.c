/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:21:42 by nacao             #+#    #+#             */
/*   Updated: 2025/01/08 16:19:26 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_rendre_input(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_y;
	int	last_x;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coin == 0)
		ft_victory_game(game);
	else if (game->map.full[new_y][new_x] == FLOOR || game->map.full[new_y][new_x] == COIN)
	{
		if (game->map.full[new_y][new_x] == COIN)
			game->map.coin--;
		game->map.full[last_y][last_x] = FLOOR;
		game->map.player.y = new_y;
		game->map.player.x = new_x;
		game->map.full[new_y][new_x] = PLAYER;
		game->movement++;
		ft_rendre_map(game);
	}
}

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == KEY_UP)
		ft_rendre_input(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_S || keysym == KEY_DOWN)
		ft_rendre_input(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		ft_rendre_input(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_D || keysym == KEY_RIGHT)
		ft_rendre_input(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_ESC || keysym == KEY_Q)
		ft_close_game(game);
	return (0);
}