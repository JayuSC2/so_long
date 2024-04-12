/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:09 by juitz             #+#    #+#             */
/*   Updated: 2024/04/12 19:23:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define _DEFAULT_SOURCE

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "../libft/libft.h"

# define TEXTURE_WIDTH 16
# define TEXTURE_HEIGHT 16
# define COLLECTIBLES_AMOUNT 3

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define KEY_ESC 65307

# define WALL_XPM "./textures/walls/wall.xpm"
# define FLOOR_XPM "./textures/floors/floor.xpm"
# define CHEST_XPM "./textures/collectibles/chest_01_0.xpm"
# define EXIT_1_XPM "./textures/exits/exit_closed.xpm"
# define OPEN_EXIT_XPM "./textures/exits/open_exit.xpm"
# define PLAYER_XPM "./textures/characters/player_front.xpm"
# define PLAYER_BACK_XPM "./textures/characters/player_back.xpm"
# define PLAYER_LEFT_XPM "./textures/characters/player_left.xpm"
# define PLAYER_RIGHT_XPM "./textures/characters/player_right.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}				t_image;

typedef struct s_data
{
	int		p_x;
	int		p_y;
	int		map_x;
	int		map_y;
	int		player_is_set;
	int		player_moves;
	int		players;
	int		fd;
	char	*line;
	char	**map;
	int		width;
	int		height;
	int		map_size;
	int		collectibles;
	int		dup_collectibles;
	int		exit;
	int		dup_exit;
	void	*mlx_ptr;
	void	*win_ptr;
	char	to_fill;
	t_image	*floor;
	t_image	*wall;
	t_image	*chest;
	t_image	*exit_1;
	t_image	*player;
	t_image	*player_back;
	t_image	*player_left;
	t_image	*player_right;
}				t_data;

int		protect_file_to_image(t_data *data);
void	print_map(char **map);
int		create_game(t_data *data);
int		create_map(t_data *data);
void	init_game(t_data *data);
void	init_map(t_data *data);
int		validate_map(t_data *data);
int		validate_path(char **dup, t_point cur, char fill_char, t_data *data);
void	init_player(t_data *data);
void	init_variables(t_data *data);
int		check_map_dimensions(t_data *data);
int		check_arguments(int argc, char **argv);
int		valid_characters(t_data *data);
void	count_parameters(t_data *data);
int		handle_input(int keysym, t_data *data);
void	movement(int keysym, t_data *data);
int		on_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);
void	ft_error(char *str);
char	*read_map(t_data *data);
int		check_map(t_data *data);
int		check_if_rectangular(t_data *data);
int		count_height(int argc, char **argv);
void	init_game(t_data *data);
void	texture_to_image(t_data *data);
void	render_map(t_data *data);
void	ft_free(char **str);

#endif