/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:22:51 by juitz             #+#    #+#             */
/*   Updated: 2024/04/12 18:58:34 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_game(t_data *data)
{
	int	w;
	int	h;

	w = data->width;
	h = data->height;
	if ((w * 16) > 1920 || (h * 16) > 1080)
		return (ft_error("Error\nMap too big\n"), ft_free(data->map), 1);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free(data->map), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (w * 16), (h * 16), "s_l");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), ft_free(data->map), 1);
	texture_to_image(data);
	render_map(data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
