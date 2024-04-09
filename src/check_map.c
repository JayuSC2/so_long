/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/09 17:56:44 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_if_rectangular(t_data *data)
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
	}
	if (i > j)
		return(ft_error("Error: map is not rectangular\n"), 1);
	return (0);
}

int		valid_characters(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
		j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != 'P' && data->map[i][j] != 'C' && data->map[i][j] != 'E')
                return(ft_error("Error: Invalid character in map\n"), 1);
            if (data->map[0][j] != '1' && data->map[data->height - 1][j] != '1')
                return(ft_error("Error: Map must be surrounded by walls\n"), 1);
            if (data->map[i][0] != '1' && data->map[i][data->width - 1] != '1')
                return(ft_error("Error: Map must be surrounded by walls\n"), 1);
            j++;
        }
        i++;
    }
	return (0);
}

/* void	count_collectibles(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'C')
            {
                data->collectibles++;
            }
            j++;
        }
        i++;
    }
	ft_printf("%d\n", data->collectibles);
    if (data->collectibles < 1)
        ft_error("Error: Invalid Map, insufficient collectibles");
} */