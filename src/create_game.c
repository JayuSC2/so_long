/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student->42->fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:48:48 by juitz             #+#    #+#             */
/*   Updated: 2024/04/08 15:50:38 by juitz            ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int   create_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free(data->map), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), ft_free(data->map), 1);
	texture_to_image(data);
	render_map(data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}