/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:20 by julian            #+#    #+#             */
/*   Updated: 2024/04/12 15:58:21 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_is_set = 1;
				data->p_x = j;
				data->p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	count_parameters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			if (data->map[i][j] == 'E')
				data->exit++;
			if (data->map[i][j] == 'P')
				data->players++;
			j++;
		}
		i++;
	}
}

void	init_game(t_data *data)
{
	init_player(data);
	count_parameters(data);
}
