/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/06 15:07:39 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(t_data *data)
{
	int texture_width;
	int texture_height;

	texture_width = TEXTURE_HEIGHT;
	texture_height = TEXTURE_WIDTH;
	
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_XPM, &texture_width, &texture_height);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR_XPM, &texture_width, &texture_height);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE1_XPM, &texture_width, &texture_height);
    data->exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_CLOSED_XPM, &texture_width, &texture_height);
    data->player_front = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_FRONT_XPM, &texture_width, &texture_height);
}

void	render_map(t_data *data)
{
	/* int height = data->map->height;
	int width = data->map->width; */
	
	data->map->height = 0;
    while (data->map->full[data->map->height])
    {
        data->map->width = 0;
        while (data->map->full[data->map->height][data->map->width])
        {
            if (data->map->full[data->map->height][data->map->width] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
            else if (data->map->full[data->map->height][data->map->width] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
            else if (data->map->full[data->map->height][data->map->width] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
            else if (data->map->full[data->map->height][data->map->width] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_closed, data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
            else if (data->map->full[data->map->height][data->map->width] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
            data->map->width++;
        }
    	data->map->height++;
    }
}



