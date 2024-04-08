/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:17:03 by juitz             #+#    #+#             */
/*   Updated: 2024/04/08 15:22:00 by juitz            ###   ########.fr       */
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
	t_data 	data;
	char	*line;
	
	ft_bzero(&data, sizeof(data));
	//init_game(&data);

	check_arguments(argc, argv);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		return (1);
	//CREATE MAP
	ft_printf("%s\n", "test3\n");
	line = read_map(&data);
	if (!line)
		//free
		return (1);
	//check str for empty lines!!!!!!!!!!!!!!!!!!!!
	data.map = ft_split(line, '\n');
	if (data.map == NULL)
		//free
		return (1);
		
 	int i = 0;
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i]);
		i++;
	}
	// ////read_map(argc, argv, &data);
	// check_if_rectangular(&data);
	// ft_printf("%s", "test4\n");
	// ft_printf("%s", "test5\n");


	//CREATE/RUN GAME
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	texture_to_image(&data);
	ft_printf("%s", "test6\n");



	
	render_map(&data);
	ft_printf("%s", "test7\n");
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	////mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}