/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:21:59 by julian            #+#    #+#             */
/*   Updated: 2024/04/13 13:51:10 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_dimensions(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	while (data->map[height] != NULL)
		height++;
	data->height = height;
	width = 0;
	if (data->map[0] != NULL)
	{
		while (data->map[0][width])
			width++;
	}
	data->width = width;
	data->map_size = (data->width * data->height);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
}
