/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/13 13:53:52 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_rectangular(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->width)
			return (1);
		i++;
	}
	return (0);
}

int	valid_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
			&& data->map[i][j] != 'P' && data->map[i][j] != 'C'
			&& data->map[i][j] != 'E')
				return (ft_error("Error\nInvalid character in map.\n"), 1);
			if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
				return (ft_error("Error\nMap must be surrounded by W.\n"), 1);
			if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
				return (ft_error("Error\nMap must be surrounded by W.\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_path(char **dup, t_point cur, char fill_char, t_data *data)
{
	if (data->dup_exit == 0 && data->dup_collectibles == 0)
		return (0);
	if (dup[cur.y][cur.x] == '1' || dup[cur.y][cur.x] == 'V')
		return (1);
	if (dup[cur.y][cur.x] == 'C')
		data->dup_collectibles--;
	if (dup[cur.y][cur.x] == 'E')
	{
		data->dup_exit--;
		dup[cur.y][cur.x] = 'V';
		return (1);
	}
	dup[cur.y][cur.x] = 'V';
	validate_path(dup, (t_point){cur.x + 1, cur.y}, fill_char, data);
	validate_path(dup, (t_point){cur.x - 1, cur.y}, fill_char, data);
	validate_path(dup, (t_point){cur.x, cur.y + 1}, fill_char, data);
	validate_path(dup, (t_point){cur.x, cur.y - 1}, fill_char, data);
	if (data->dup_exit == 1)
		return (1);
	if (data->dup_exit == 0 && data->dup_collectibles == 0)
		return (0);
	return (1);
}

int	validate_map(t_data *data)
{
	char	**dup;
	t_point	cur;

	data->dup_collectibles = data->collectibles;
	data->dup_exit = data->exit;
	ft_bzero(&cur, sizeof(cur));
	dup = ft_strarraydup(data->map);
	if (!dup)
		return (1);
	cur.x = data->p_x;
	cur.y = data->p_y;
	if (validate_path(dup, cur, dup[cur.y][cur.x], data) == 1)
		return (ft_free(dup), 1);
	ft_free(dup);
	return (0);
}

int	check_map(t_data *data)
{
	if (data->players != 1)
		return (ft_error("Error\nInvalid Map, incorrect number of P.\n"), 1);
	if (data->collectibles < 1)
		return (ft_error("Error\nInvalid Map, insufficient C.\n"), 1);
	if (data->exit != 1)
		return (ft_error("Error\nInvalid Map, incorrect number of E.\n"), 1);
	check_map_dimensions(data);
	if (check_if_rectangular(data) == 1)
		return (ft_error("Error\nMap is not rectangular.\n"), 1);
	if (valid_characters(data) == 1)
		return (1);
	if (validate_map(data) == 1)
		return (ft_error("Error\nInvalid player path.\n"), 1);
	return (0);
}
