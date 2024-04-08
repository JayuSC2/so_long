/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/08 14:50:58 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_if_rectangular(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data-full>map->[i])
	{
		j = 0;
		while (data->map->full[i][j])
			j++;
		i++;
		if (i > j)
			ft_error("Error, map is not rectangular");
	}
}

void	valid_characters(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map->full[i])
    {
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] != '1' && data->map->full[i][j] != '0' && data->map->full[i][j] != 'P' && data->map->full[i][j] != 'C' && data->map->full[i][j] != 'E')
                ft_error("Error\nInvalid map3");
            if (data->map->full[0][j] != '1' && data->map->full[data->map->height - 1][j] != '1')
                ft_error("Error\nInvalid map4");
            if (data->map->full[i][0] != '1' && data->map->full[i][data->map->width - 1] != '1')
                ft_error("Error\nInvalid map5");
            j++;
        }
        i++;
    }
} 
