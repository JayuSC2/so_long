/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/01/19 14:00:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_data *t_map)
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
            j++;
        }
        i++;
    }
}

void read_map(t_data *data, char *argv)
{
    int fd;
    char *line;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    data->map->height = 0;
	while ((line = get_next_line(fd)))
    {
        data->map = realloc(data->map, sizeof(char *) * (data->map->height + 2));
        if (!data->map)
            ft_error("Error\nInvalid map");
        data->map[data->map->height] = line;
        data->map[data->map->height + 1] = NULL;
        data->map->height++;
    }
    map_check(data);
    close(fd);
}

/* int main(int argc, char **argv)
{
    t_data *data;

    if (argc != 2)
        ft_error("Error\nInvalid map");
    data = malloc(sizeof(t_data));
    if (!data)
        ft_error("Error\nMemory allocation failed");
    data->map = malloc(sizeof(t_map));
    if (!data->map)
        ft_error("Error\nMemory allocation failed");
    read_map(data, argv[1]);
    return (0);
} */

