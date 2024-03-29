/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:35:29 by julian            #+#    #+#             */
/*   Updated: 2024/03/28 15:34:59 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void map_check()
/* 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return(0);
}
int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}
 */
/* int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	mlx_loop(data.mlx_ptr);
	return (0);
} */
/* int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init;
	if (!mlx_ptr)
		return (1);
	free(mlx_ptr);
	return (0);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "test");
	if (!win_ptr)
		return(free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
} */