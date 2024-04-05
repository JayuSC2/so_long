/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/05 17:50:03 by juitz            ###   ########.fr       */
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
	int height = data->map->height;
	int width = data->map->width;
	
	height = 0;
    while (data->map->full[height])
    {
        width = 0;
        while (data->map->full[height][width])
        {
            if (data->map->full[height][width] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, width * TEXTURE_WIDTH, height * TEXTURE_HEIGHT);
            else if (data->map->full[height][width] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, width * TEXTURE_WIDTH, height * TEXTURE_HEIGHT);
            else if (data->map->full[height][width] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, width * TEXTURE_WIDTH, height * TEXTURE_HEIGHT);
            else if (data->map->full[height][width] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_closed, width * TEXTURE_WIDTH, height * TEXTURE_HEIGHT);
            else if (data->map->full[height][width] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, width * TEXTURE_WIDTH, height * TEXTURE_HEIGHT);
            width++;
        }
    	height++;
    }
}



