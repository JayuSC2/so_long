/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/04/13 13:56:05 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	texture_to_image(t_data *data)
{
	int	w;
	int	h;

	w = TEXTURE_WIDTH;
	h = TEXTURE_HEIGHT;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_XPM, &w, &h);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR_XPM, &w, &h);
	data->chest = mlx_xpm_file_to_image(data->mlx_ptr, CHEST_XPM, &w, &h);
	data->exit_1 = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_1_XPM, &w, &h);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_XPM, &w, &h);
	if (protect_file_to_image(data) == 1)
		return (1);
	return (0);
}

void	render_map(t_data *data)
{
	data->map_y = 0;
	while (data->map[data->map_y])
	{
		data->map_x = 0;
		while (data->map[data->map_y][data->map_x])
		{
			if (data->map[data->map_y][data->map_x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall, data->map_x * 16, data->map_y * 16);
			else if (data->map[data->map_y][data->map_x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->floor, data->map_x * 16, data->map_y * 16);
			else if (data->map[data->map_y][data->map_x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->chest, data->map_x * 16, data->map_y * 16);
			else if (data->map[data->map_y][data->map_x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit_1, data->map_x * 16, data->map_y * 16);
			else if (data->map[data->map_y][data->map_x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->player, data->map_x * 16, data->map_y * 16);
			data->map_x++;
		}
		data->map_y++;
	}
}

int	protect_file_to_image(t_data *data)
{
	if (!data->wall || !data->floor || !data->chest
		|| !data->exit_1 || !data->player)
		return (ft_error("Error\nXPM to Image failed."), on_destroy(data), 1);
	return (0);
}
