/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:27:11 by juitz             #+#    #+#             */
/*   Updated: 2024/04/09 17:03:55 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_down(int keysym, t_data *data)
{
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		if (data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
		{
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y - 1][data->player_x] = 'P';
			data->player_y--;
			data->player_moves++;
			ft_printf("Number of Movement(s): %d\n", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->player_x * 16, (data->player_y + 1) * 16);
		}
	}
	if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		if (data->map[data->player_y + 1][data->player_x] != '1' && data->map[data->player_y + 1][data->player_x] != 'E')
		{
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y + 1][data->player_x] = 'P';
			data->player_y++;
			data->player_moves++;
			ft_printf("Number of Movement(s): %d\n", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->player_x * 16, (data->player_y - 1) * 16);
		}
	}
}

void	left_right(int keysym, t_data *data)
{
	if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		if (data->map[data->player_y][data->player_x - 1] != '1' && data->map[data->player_y][data->player_x - 1] != 'E')
		{
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y][data->player_x - 1] = 'P';
			data->player_x--;
			data->player_moves++;
			ft_printf("Number of Movement(s): %d\n", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, (data->player_x + 1) * 16, data->player_y * 16);
		}
	}
	if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		if (data->map[data->player_y][data->player_x + 1] != '1' && data->map[data->player_y][data->player_x + 1] != 'E')
		{
			data->map[data->player_y][data->player_x] = '0';
			data->map[data->player_y][data->player_x + 1] = 'P';
			data->player_x++;
			data->player_moves++;
			ft_printf("Number of Movement(s): %d\n", data->player_moves);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_front, data->player_x * 16, data->player_y * 16);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, (data->player_x - 1) * 16, data->player_y * 16);
		}
	}
}

int close_game(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		ft_printf("The %d key (ESC) has been pressed!", keysym);
		on_destroy(data);
	}
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	//if (keysym == KEY_W || keysym == KEY_UP)
	up_down(keysym, data);
	left_right(keysym, data);
	close_game(keysym, data);
	//ft_printf("Pressed key: %d\n", keysym);
	return (0);
}