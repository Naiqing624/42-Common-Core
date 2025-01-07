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

int main(int argc, char **argv)
{
	t_game  *game;

    game = malloc(sizeof(t_game));
    ft_check_arg(argc, argv, game);
    ft_initia_map(game, argv[1]);
    ft_initia_var(game);
    ft_check_map(game);
    ft_initia_mlx_win(game);
    ft_initia_sprites(game);
}
