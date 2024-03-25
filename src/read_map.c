/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2024/03/25 17:27:54 by juitz            ###   ########.fr       */
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

void	map_check(t_data *t_data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (t_data->map->full[i])
    {
        while (t_data->map->full[i][j])
        {
            if (t_data->map->full[i][j] != '1' && t_data->map->full[i][j] != '0' && t_data->map->full[i][j] != 'P' && t_data->map->full[i][j] != 'C' && t_data->map->full[i][j] != 'E')
                ft_error("Error\nInvalid map");
            if (t_data->map->full[0][j] != '1' && t_data->map->full[t_data->map->height - 1][j] != '1')
                ft_error("Error\nInvalid map");
            if (t_data->map->full[i][0] != '1' && t_data->map->full[i][t_data->map->width - 1] != '1')
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
    while (data->map->full[i])
    {
        j = 0;
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] == 'C')
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
        data->map->full = realloc(data->map->full, sizeof(char *) * (data->map->height + 2));
        if (!data->map->full)
            ft_error("Error\nInvalid map");
        data->map->full[data->map->height] = line;
        data->map->full[data->map->height + 1] = NULL;
        data->map->height++;
    }
    close(fd);
    map_check(data);
}
