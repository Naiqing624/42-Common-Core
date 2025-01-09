/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:06:25 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 20:06:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/lib/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define PLAYER				'P'
# define COIN				'C'
# define MAP_EXIT			'E'
# define FLOOR				'0'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_ESC			65307
# define KEY_Q				113

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define COIN_XPM			"assets/sprites/coin.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define WALL_XPM			"assets/sprites/wall.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/players/back.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/players/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/players/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/players/right.xpm"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coin;
	int			exit;
	int			players;
	t_position	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movement;
	int			player_sprite;
	t_map		map;
	t_bool		map_malloc;
	t_image		wall;
	t_image		floor;
	t_image		player_front;
	t_image		player_back;
	t_image		player_right;
	t_image		player_left;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		coin;
}	t_game;

//check_argc
void	ft_check_arg(int argc, char **argv, t_game *game);

//error_free
void	ft_free_map(t_game *game);
int		ft_error_message(char *message, t_game *game);
void	ft_free_all_memery(t_game *game);

//initialize Map .ber to game->map.full
void	check_empty_line(t_game *game, char *map);
char	*ft_strappend(char **s1, char *s2);
void	ft_initia_map(t_game *game, char *argv);

//initialize variable of map
void	ft_initia_var(t_game *game);

//check map, set parametre and check itself
void	ft_check_map(t_game *game);

//initialize mlx and win
void	ft_initia_mlx_win(t_game *game);

//Load and initialize the sprites needed for the game
void	ft_initia_sprites(t_game *game);

//rendre game
int		ft_rendre_map(t_game *game);

//quit game
int		ft_victory_game(t_game *game);
int		ft_close_game(t_game *game);

//handle input - give the reation to keypress
int		ft_handle_input(int keysym, t_game *game);

#endif