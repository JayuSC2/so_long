/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:17:03 by juitz             #+#    #+#             */
/*   Updated: 2024/04/12 15:46:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->chest);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->exit_1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free(data->map);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (check_arguments(argc, argv) == 1)
		return (1);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		return (1);
	if (create_map(&data) == 1)
		return (free(data.line), 1);
	data.map = ft_split(data.line, '\n');
	if (data.map == NULL)
		//free
		return (free(data.line), 1);
	free(data.line);
	init_game(&data);
	if (check_map(&data) == 1)
		return (ft_free(data.map), 1);
	create_game(&data);
	return (0);
}

/* void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
} */