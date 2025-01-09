/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:27:33 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:26:47 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//free two dimension map
//frist free each row
//release the pointer arrey that stores pointers to each rows (game->map.full)
void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.full[i++]);
	}
	free(game->map.full);
}

int	ft_error_message(char *message, t_game *game)
{
	if (game->map_malloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("Error\n%s\n", message);
	exit (EXIT_FAILURE);
}

void	ft_destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->coin.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
}

void	ft_free_all_memery(t_game *game)
{
	ft_destroy_image(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
