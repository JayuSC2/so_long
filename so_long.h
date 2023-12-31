/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:09 by juitz             #+#    #+#             */
/*   Updated: 2023/12/31 15:38:46 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include "./libft/libft.h"

#define TILE_SIZE 64
#define WINDOW_TITLE "so_long"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}				t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	*map;
}				t_data;

int on_destroy(t_data *data);
int	on_keypress(int keysym, t_data *data);
int get_next_line(int fd, char **line);
void	ft_error(char *str);
void    read_map(t_data *t_map, char *argv);
void	map_check(t_data *t_map);

#endif