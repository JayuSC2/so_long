/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/09 17:29:04 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	texture_to_image(t_data *data)
{
	int w;
	int h;

	w = TEXTURE_WIDTH;
	h = TEXTURE_HEIGHT;
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_XPM, &w, &h);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR_XPM, &w, &h);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE1_XPM, &w, &h);
    data->exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_CLOSED_XPM, &w, &h);
    data->player_front = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_FRONT_XPM, &w, &h);
	/* if (!data->wall || !data->floor || !data->collectible || !data->exit_closed || !data->player_front)
		return(ft_free(data->map, mlx_destroy_image())) */
}

void	render_map(t_data *data)
{
	int i;
	int j;
	
	i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, j * 16, i * 16);
            else if (data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, j * 16, i * 16);
            else if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, j * 16, i * 16);
            else if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_closed, j * 16, i * 16);
            else if (data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, j * 16, i * 16);
            j++;
        }
    	i++;
    }
}
