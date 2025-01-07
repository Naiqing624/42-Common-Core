/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:26:29 by nacao             #+#    #+#             */
/*   Updated: 2025/01/07 13:21:54 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_arg(int argc, char **argv, t_game *game)
{
	int	len;

	game->map_malloc = false;
	if (argc > 2)
		ft_error_message("Too much arguments", game);
	else if (argc < 2)
		ft_error_message("Missing map", game);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
		ft_error_message("Map extention is wrong", game);
}

