/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:09 by juitz             #+#    #+#             */
/*   Updated: 2024/04/04 18:49:42 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "../libft/libft.h"

#define WINDOW_TITLE "so_long"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TEXTURE_WIDTH 16
#define TEXTURE_HEIGHT 16
#define COLLECTIBLES_AMOUNT 3

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGHT 65363

#define KEY_ESC 65307

#define WALL_XPM "./textures/wall.xpm"
#define FLOOR_XPM "./textures/floor.xpm"
#define COLLECTIBLE_XPM "./textures/collectible.xpm"
#define CLOSED_EXIT_XPM "./textures/closed_exit.xpm"
#define OPEN_EXIT_XPM "./textures/open_exit.xpm"
#define PLAYER_FRONT_XPM "./textures/player_front.xpm"
#define PLAYER_BACK_XPM "./textures/player_back.xpm"
#define PLAYER_LEFT_XPM "./textures/player_left.xpm"
#define PLAYER_RIGHT_XPM "./textures/player_right.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef struct s_point
{
	int size;
	int cur;
	int x;
	int y;
}				t_point;

typedef struct s_player
{
	int		x;
	int		y;
	int		is_set;
	int		moves;
}				t_player; 

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}				t_image;

typedef struct s_map
{
	char	**full;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	t_player		player;
}				t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	to_fill;
	t_image *floor;
	t_image *wall;
	t_image *collectible;
	t_image *exit_closed;
	t_image *player_front;
	t_image *player_back;
	t_image *player_left;
	t_image *player_right;
	t_map	*map;
}				t_data;

void	check_arguments(int argc, char **argv);
int		on_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);
void	ft_error(char *str);
void 	read_map(char **argv);
void	map_check(t_data *data);
void	count_collectibles(t_data *data);
void	init_game(t_data *data);
void	texture_to_image(t_data *data);
void	init_player(t_data *data);
void	init_variables(t_data *data);
int		render_map(t_data *data);


#endif