/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:17:03 by juitz             #+#    #+#             */
/*   Updated: 2024/04/07 15:54:42 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return(0);
}
/* int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
} */

int main(int argc, char **argv)
{
	t_data data;

	init_game(&data);
/* 	if (argc < 2)
		ft_putendl_fd("Error: please provide a valid map", 2);
	if (argc > 2)
		ft_putendl_fd("Error: too many arguments", 2); */
	check_arguments(argc, argv);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	read_map(argc, argv, &data);
	ft_printf("%s", "test4\n");
	init_player(&data);
	ft_printf("%s", "test5\n");
	texture_to_image(&data);
	ft_printf("%s", "test6\n");
	render_map(&data);
	ft_printf("%s", "test7\n");
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}