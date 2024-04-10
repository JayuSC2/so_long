/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/10 20:07:33 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_map_dimensions(t_data *data)
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
	ft_printf("%d\n", data->height);
	ft_printf("%d\n", data->width);
}

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
		if (j != data->width)
			return(ft_error("Error: Map is not rectangular\n"), 1);
		i++;
	}
	if (i > j)
		return (ft_error("Error: Map is not rectangular\n"), 1);
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
            if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
                return(ft_error("Error: Map must be surrounded by walls\n"), 1);
            if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
                return(ft_error("Error: Map must be surrounded by walls\n"), 1);
            j++;
        }
        i++;
    }
	return (0);
}

void	validate_path(char **map, t_point size, t_point cur, char fill_char, t_data *data)
{
	char **dup;

	map = data->map;
	dup = ft_strarraydup(map);
	if (!dup)
		return (NULL);
	cur.x = data->player_x;
	cur.y = data->player_y;

	/* if(cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y)
		return; */
	if (dup[cur.x][cur.y] == '1' || dup[cur.x][cur.y] == 'V')
		return ;
	if (dup[cur.x][cur.y] == 'C')
		data->collectibles--;
	if (dup[cur.x][cur.y] == 'E' && data->collectibles != 0)
		return ;
	if (dup[cur.x][cur.y] == 'E')
		data->exit--;
	{
		if (fill_char == 'P')
			return ;
		else
		{
			ft_error("Error: Invalid Map, exit not reachable\n");
			ft_free(dup);
			return ;
		}
	}
	dup[cur.x][cur.y] = 'V';
	validate_path(dup, size, (t_point){cur.x + 1, cur.y}, fill_char, data);
	validate_path(dup, size, (t_point){cur.x - 1, cur.y}, fill_char, data);
	validate_path(dup, size, (t_point){cur.x, cur.y + 1}, fill_char, data);
	validate_path(dup, size, (t_point){cur.x, cur.y - 1}, fill_char, data);
	ft_free(dup);
}

void	validate_map(char **map, t_point size, t_point begin, t_data *data)
{
	validate_path(data->map, size, begin, data->map[begin.x][begin.y], data);
}


int		check_map(t_data *data)
{
	if (data->players != 1)
        return (ft_error("Error: Invalid Map, incorrect number of players(1)\n"), 1);
	if (data->collectibles < 1)
        return (ft_error("Error: Invalid Map, insufficient collectibles\n"), 1);
	if (data->exit != 1)
		return (ft_error("Error: Invalid Map, incorrect number of exits(1)\n"), 1);
	calculate_map_dimensions(data);
	if (valid_characters(data) == 1)
		return(1);
	check_if_rectangular(data);
	//get dup
	//check NULL for dup
	//return if NULL, free EVYRETHING
	//check_path
	//free dup
	return (0);	
}