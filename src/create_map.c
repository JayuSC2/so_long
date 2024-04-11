/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:45:06 by juitz             #+#    #+#             */
/*   Updated: 2024/04/09 18:11:51 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		create_map(t_data *data)
{
	data->line = read_map(data);
	if (!data->line)
		//free
		return (1);
	int count = 0;
	while (data->line && data->line[count])
	{
		if (data->line[0] == '\n')
			return (ft_error("Error: empty line in beginning of file\n"), 1);
		if (data->line[count] == '\n' && data->line[count + 1] == '\n')
			return (ft_error("Error: empty line in file\n"), 1);
		if (data->line[ft_strlen(data->line) - 1] == '\n')
			return (ft_error("Error: empty line at the end of file\n"), 1);
		count++;
	}
	return (0);
}