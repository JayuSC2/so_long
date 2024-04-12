/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:21:10 by juitz             #+#    #+#             */
/*   Updated: 2024/04/12 14:19:54 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(int keysym, t_data *data)
{
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		if (data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
		{
			if (data->map[data->player_y - 1][data->player_x] == 'C')
				data->collectibles--;
			ft_printf("\nNumber of collectibles: %d\n", data->collectibles);
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y - 1][data->player_x] = 'P';
			data->player_y--;
			data->player_moves++;
			ft_printf("\rNumber of Movement(s): %d", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->player_x * 16, (data->player_y + 1) * 16);
		}
		if ((data->map[data->player_y - 1][data->player_x] == 'E')
		&& (data->collectibles == 0))
		{
			ft_printf("\nCongratulations: You won\n");
			on_destroy(data);
		}	
	}
}
void	down(int keysym, t_data *data)
{
	if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		if (data->map[data->player_y + 1][data->player_x] != '1' 
		&& data->map[data->player_y + 1][data->player_x] != 'E')
		{
			if (data->map[data->player_y + 1][data->player_x] == 'C')
				data->collectibles--;
			ft_printf("\nNumber of collectibles: %d\n", data->collectibles);
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y + 1][data->player_x] = 'P';
			data->player_y++;
			data->player_moves++;
			ft_printf("\rNumber of Movement(s): %d", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->player_x * 16, (data->player_y - 1) * 16);
		}
		if ((data->map[data->player_y + 1][data->player_x] == 'E')
		&& (data->collectibles) == 0)
		{
			ft_printf("\nCongratulations: You won\n");
			on_destroy(data);
		}	
				
	}
}

void	left(int keysym, t_data *data)
{
	if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		if (data->map[data->player_y][data->player_x - 1] != '1'
		&& data->map[data->player_y][data->player_x - 1] != 'E')
		{
			if (data->map[data->player_y][data->player_x - 1] == 'C')
				data->collectibles--;
			ft_printf("\nNumber of collectibles: %d\n", data->collectibles);
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y][data->player_x - 1] = 'P';
			data->player_x--;
			data->player_moves++;
			ft_printf("\rNumber of Movement(s): %d", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, (data->player_x + 1) * 16, data->player_y * 16);
		}
		if ((data->map[data->player_y][data->player_x - 1] == 'E')
		&& (data->collectibles == 0))
		{
			ft_printf("\nCongratulations: You won\n");
			on_destroy(data);
		}	
	}
}

void	right(int keysym, t_data *data)
{
	if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		if (data->map[data->player_y][data->player_x + 1] != '1'
		&& data->map[data->player_y][data->player_x + 1] != 'E')
		{
			if (data->map[data->player_y][data->player_x + 1] == 'C')
				data->collectibles--;
			ft_printf("\nNumber of collectibles: %d\n", data->collectibles);
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y][data->player_x + 1] = 'P';
			data->player_x++;
			data->player_moves++;
			ft_printf("\rNumber of Movement(s): %d", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, (data->player_x - 1) * 16, data->player_y * 16);
		}
		if ((data->map[data->player_y][data->player_x + 1] == 'E')
		&& (data->collectibles == 0))
		{
			ft_printf("\nCongratulations: You won\n");
			on_destroy(data);
		}	
	}
}

void	movement(int keysym, t_data *data)
{
	up(keysym, data);
	down(keysym, data);
	left(keysym, data);
	right(keysym, data);
}
