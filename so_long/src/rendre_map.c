/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendre_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:35:32 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:31:49 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_movement(t_game *game)
{
	char	*movement;
	char	*phrase;

	movement = ft_itoa(game->movement);
	phrase = ft_strjoin("Movement: ", movement);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movement);
	free(phrase);
}

void	ft_image_to_window(t_game *game, t_image sprite, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		sprite.xpm_ptr, x * sprite.x, y * sprite.y);
}

void	ft_rendre_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_image_to_window(game, game->player_front, y, x);
	if (game->player_sprite == BACK)
		ft_image_to_window(game, game->player_back, y, x);
	if (game->player_sprite == LEFT)
		ft_image_to_window(game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_image_to_window(game, game->player_right, y, x);
}

void	ft_rendre_sprites(t_game *game, int y, int x)
{
	char	current_position;

	current_position = game->map.full[y][x];
	if (current_position == COIN)
		ft_image_to_window(game, game->coin, y, x);
	else if (current_position == FLOOR)
		ft_image_to_window(game, game->floor, y, x);
	else if (current_position == WALL)
		ft_image_to_window(game, game->wall, y, x);
	else if (current_position == MAP_EXIT)
	{
		if (game->map.coin == 0)
			ft_image_to_window(game, game->open_exit, y, x);
		else
			ft_image_to_window(game, game->exit_closed, y, x);
	}
	else if (current_position == PLAYER)
		ft_rendre_player(game, y, x);
}

int	ft_rendre_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_rendre_sprites(game, y, x);
			x++;
		}
		y++;
	}
	print_movement(game);
	return (0);
}
