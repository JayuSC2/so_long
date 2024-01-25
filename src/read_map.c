/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2024/01/22 19:47:29 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_arguments(int argc, char **argv)
{
    if (argc != 2)
        ft_error("Error\nInvalid map");
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
        ft_error("Error\nInvalid map");
}

void	map_check(t_data  *t_map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (t_map->map[i])
    {
        while (t_map->map[i][j])
        {
            if (t_map->map[i][j] != '1' && t_map->map[i][j] != '0' && t_map->map[i][j] != 'P' && t_map->map[i][j] != 'C' && t_map->map[i][j] != 'E')
                ft_error("Error\nInvalid map");
            if (t_map->map[0][j] != '1' && t_map->map[t_map->map->height - 1][j] != '1')
                ft_error("Error\nInvalid map");
            if (t_map->map[i][0] != '1' && t_map->map[i][t_map->map->width - 1] != '1')
                ft_error("Error\nInvalid map");
            j++;
        }
        i++;
    }
}

void count_collectibles(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->map->collectibles = 0;
    while (data->map->map[i])
    {
        j = 0;
        while (data->map->map[i][j])
        {
            if (data->map->map[i][j] == 'C')
                data->map->collectibles++;
            j++;
        }
        i++;
    }
}

void	read_map (t_data *data, char *argv)
{
    int		fd;
    char	*line;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    data->map->height = 0;
    while ((line = get_next_line(fd)))
    {
        data->map->map = realloc(data->map->map, sizeof(char *) * (data->map->height + 2));
        if (!data->map->map)
            ft_error("Error\nInvalid map");
        data->map->map[data->map->height] = line;
        data->map->map[data->map->height + 1] = NULL;
        data->map->height++;
    }
    close(fd);
    map_check(data);
}
