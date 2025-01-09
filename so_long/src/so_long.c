/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:37:40 by nacao             #+#    #+#             */
/*   Updated: 2025/01/07 16:37:40 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\nMemory allocation failed\n");
		return (EXIT_FAILURE);
	}
	ft_check_arg(argc, argv, game);
	ft_initia_map(game, argv[1]);
	ft_initia_var(game);
	ft_check_map(game);
	ft_initia_mlx_win(game);
	ft_initia_sprites(game);
	ft_rendre_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify,
		ButtonPressMask, ft_close_game, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_rendre_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_memery(game);
	return (EXIT_SUCCESS);
}
