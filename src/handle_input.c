/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:27:11 by juitz             #+#    #+#             */
/*   Updated: 2024/04/07 13:16:24 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int up_down(int keysym, t_data *data)
{
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		if (data->map->full[data->map->player.y - 1][data->map->player.x] == '0')
		{
			data->map->full[data->map->player.y][data->map->player.x] = '0';
			data->map->full[data->map->player.y - 1][data->map->player.x] = 'P';
			data->map->player.y -= 1;
			data->map->player.moves++;
		}
	}
	else if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		if (data->map->full[data->map->player.y + 1][data->map->player.x] == '0')
		{
			data->map->full[data->map->player.y][data->map->player.x] = '0';
			data->map->full[data->map->player.y + 1][data->map->player.x] = 'P';
			data->map->player.y += 1;
			data->map->player.moves++;
		}
	}
	return (0);
}

int left_right(int keysym, t_data *data)
{
	if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		if (data->map->full[data->map->player.y][data->map->player.x - 1] == '0')
		{
			data->map->full[data->map->player.y][data->map->player.x] = '0';
			data->map->full[data->map->player.y][data->map->player.x - 1] = 'P';
			data->map->player.x -= 1;
			data->map->player.moves++;
		}
	}
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		if (data->map->full[data->map->player.y][data->map->player.x + 1] == '0')
		{
			data->map->full[data->map->player.y][data->map->player.x] = '0';
			data->map->full[data->map->player.y][data->map->player.x + 1] = 'P';
			data->map->player.x += 1;
			data->map->player.moves++;
		}
	}
	return (0);
}

int close_game(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		printf("The %d key (ESC) has been pressed!", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	up_down(keysym, data);
	left_right(keysym, data);
	close_game(keysym, data);
	printf("Pressed key: %d\n", keysym);
	return (0);
}