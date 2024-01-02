/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:13:29 by julian            #+#    #+#             */
/*   Updated: 2023/12/31 15:44:52 by julian           ###   ########.fr       */
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

void    read_map(t_data *t_map, char *argv)
{
    int fd;
    int ret;
    char *line;
    int i;

    i = 0;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        t_map->map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    t_map->map[i] = ft_strdup(line);
    free(line);
    close(fd);
    map_check(t_map);
}

int main(int argc, char **argv)
{
    t_data t_map;

    if (argc != 2)
        ft_error("Error\nInvalid map");
    t_map.map = malloc(sizeof(t_map.map));
    if (!t_map.map)
        ft_error("Error\nInvalid map");
    read_map(&t_map, argv[1]);
    return (0);
}



