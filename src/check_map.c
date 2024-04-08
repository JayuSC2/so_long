/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/08 15:55:17 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_if_rectangular(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
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
    while (data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != 'P' && data->map[i][j] != 'C' && data->map[i][j] != 'E')
                ft_error("Error\nInvalid map3");
            if (data->map[0][j] != '1' && data->map[data->height - 1][j] != '1')
                ft_error("Error\nInvalid map4");
            if (data->map[i][0] != '1' && data->map[i][data->width - 1] != '1')
                ft_error("Error\nInvalid map5");
            j++;
        }
        i++;
    }
}

void empty_lines_check (t_data *data)
{
	
}
