/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/06 16:30:30 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(t_data *data)
{
	int w;
	int h;

	w = TEXTURE_HEIGHT;
	h = TEXTURE_WIDTH;
	
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_XPM, &w, &h);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR_XPM, &w, &h);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE1_XPM, &w, &h);
    data->exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_CLOSED_XPM, &w, &h);
    data->player_front = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_FRONT_XPM, &w, &h);
}

void	render_map(t_data *data)
{
	/* int height = data->map->height;
	int width = data->map->width; */
	int i;
	int j;
	
	//data->map = malloc(sizeof(t_map));
	i = 0;
    while (i < data->map->height)
    {
        j = 0;
        while (j < data->map->width)
        {
            if (data->map->full[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, i, j);
            else if (data->map->full[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, i, j);
            else if (data->map->full[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, i, j);
            else if (data->map->full[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_closed, i, j);
            else if (data->map->full[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, i, j);
            j++;
        }
    	i++;
    }
}



