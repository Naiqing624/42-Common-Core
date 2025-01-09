/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initia_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:23:24 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:29:35 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//check if mao have empty line inside
void	check_empty_line(t_game *game, char *map)
{
	int	i;

	if (!map || map[0] == '\n')
	{
		ft_error_message("Invalid Map", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_message("Invalid Map", game);
	}
	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_message("Invalid Map", game);
		}
		i++;
	}
}

//put two strings in a new string
char	*ft_strappend(char **s1, char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s2) + ft_strlen(*s1) + 1);
	free(*s1);
	return (str);
}

//initiate the map with getnextline to read the .ber file
//save its into two dimension map
void	ft_initia_map(t_game *game, char *argv)
{
	char	*line_map;
	char	*map_tmp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_message("Reading map error", game);
	map_tmp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_map = get_next_line(map_fd);
		if (line_map == NULL)
			break ;
		map_tmp = ft_strappend(&map_tmp, line_map);
		free(line_map);
		game->map.rows++;
	}
	close(map_fd);
	check_empty_line(game, map_tmp);
	game->map.full = ft_split(map_tmp, '\n');
	game->map_malloc = true;
	free(map_tmp);
}
