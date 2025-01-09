/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initia_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:22:03 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:30:49 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_initia_var(t_game *game)
{
	game->map.coin = 0;
	game->map.players = 0;
	game->map.exit = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->movement = 0;
	game->player_sprite = FRONT;
}

void	ft_initia_mlx_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_error_message("Couldn't find mlx pointer", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_message("Couldn't open window", game);
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.y, &sprite.x);
	if (!sprite.xpm_ptr)
		ft_error_message(ft_strjoin("Couldn't find sprite: ", path), game);
	return (sprite);
}

void	ft_initia_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->coin = ft_new_sprite(mlx, COIN_XPM, game);
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}
