/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2024/04/12 16:54:36 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error\nUsage: ./so_long <mapname>\n"), 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (ft_error("Error\nMap has to be .ber file\n"), 1);
	return (0);
}

char	*read_map(t_data *data)
{
	char	*line;
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc(1 + 1);
	if (!temp)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (free(temp), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(line, EOF)))
	{
		bytes_read = read(data->fd, temp, 1);
		if (bytes_read == -1)
			return (free(line), free(temp), NULL);
		temp[bytes_read] = '\0';
		line = ft_join_and_free(line, temp);
		if (!line)
			return (NULL);
	}
	return (free(temp), line);
}
