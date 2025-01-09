/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:35:03 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:26:40 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_message("Wall incomplet at row start", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_message("Wall incomplet at row end", game);
		i++;
	}
}

void	ft_check_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (!game->map.full[0] || !game->map.full[game->map.rows - 1])
			ft_error_message("Invalid access in column check", game);
		if (game->map.full[0][i] != WALL)
			ft_error_message("Wall incomplet at column start", game);
		if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_message("Wall incomplet at column end", game);
		i++;
	}
}

void	ft_check_set_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!(ft_strchr("CEP01", game->map.full[y][x])))
				ft_error_message("Find uncorrect sprite", game);
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			if (game->map.full[y][x] == COIN)
				game->map.coin++;
			if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_check_parametre(t_game *game)
{
	if (game->map.coin == 0)
		ft_error_message("Invalid Map. NO COINS found", game);
	else if (game->map.exit == 0)
		ft_error_message("Invalid Map. NO EXIT found", game);
	else if (game->map.players != 1)
		ft_error_message("Invalid Map. MORE THAN ONE PLAYER", game);
}

void	ft_check_map(t_game *game)
{
	ft_check_row(game);
	ft_check_column(game);
	ft_check_set_map(game);
	ft_check_parametre(game);
}
