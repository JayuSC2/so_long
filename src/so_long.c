/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:17:03 by juitz             #+#    #+#             */
/*   Updated: 2024/04/09 17:57:34 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	print_map(t_data *data)
{
	int i = 0;
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}

int on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->floor->xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall->xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->collectible->xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_front->xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->exit_closed->xpm_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free(data->map);
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
	//char	*line;
	
	ft_bzero(&data, sizeof(data));
	//init_game(&data);

	check_arguments(argc, argv);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		return (1);
	//CREATE MAP
	ft_printf("Test1\n");
	if (create_map(&data) == 1)
		return (1);
	valid_characters(&data);
	check_if_rectangular(&data);
/* 	ft_printf("Test2\n");
	line = read_map(&data);
	if (!line)
		//free
		return (1);
	int count = 0;
	while (line && line[count])
	{
		if (line[0] == '\n')
			return (ft_error("Error: empty line in beginning of file\n"), 1);
		if (line[count] == '\n' && line[count + 1] == '\n')
			return (ft_error("Error: empty line in file\n"), 1);
		if (line[ft_strlen(line) - 1] == '\n')
			return (ft_error("Error: empty line at the end of file\n"), 1);
		count++;
	} */
	//check str for empty lines!!!!!!!!!!!!!!!!!!!!
	data.map = ft_split(data.line, '\n');
	if (data.map == NULL)
		//free
		return (free(data.line), 1);
	free(data.line);
	init_player(&data);
	count_collectibles(&data);
	create_game(&data);
	return (0);
}