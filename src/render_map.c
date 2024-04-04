/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/04 18:49:20 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(t_data *data)
{
	int texture_width;
	int texture_height;

	texture_width = TEXTURE_HEIGHT;
	texture_height = TEXTURE_WIDTH;
	
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/walls/wall.xpm", &texture_width, &texture_height);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor/floors.xpm", &texture_width, &texture_height);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/collectibles/chest_01_0.xpm", &texture_width, &texture_height);
    data->exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exits/exit_closed.xpm", &texture_width, &texture_height);
    data->player_front = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/characters/player_front.xpm", &texture_width, &texture_height);
}

int render_map (t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map->full[i])
    {
        j = 0;
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_closed, j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            j++;
        }
        i++;
    }
    return (0);
}



