/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:27:33 by nacao             #+#    #+#             */
/*   Updated: 2025/01/07 13:08:45 by nacao            ###   ########.fr       */
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
	if (game->map_malloc = true)
		ft_free_map(game);
	free(game);
	ft_printf("Error\n%s\n", message);
	exit (EXIT_FAILURE);
}