/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:52 by julian            #+#    #+#             */
/*   Updated: 2024/04/03 14:33:19 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "so_long.h"

void	map_check(t_data *t_map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (t_map->map->full[i])
    {
        while (t_map->map->full[i][j])
        {
            if (t_map->map->full[i][j] != '1' && t_map->map->full[i][j] != '0' && t_map->map->full[i][j] != 'P' && t_map->map->full[i][j] != 'C' && t_map->map->full[i][j] != 'E')
                ft_error("Error\nInvalid map");
            j++;
        }
        i++;
    }
}

void	read_map(t_data *t_map, char *argv)
{
    int fd;
    char *line;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map");
    t_map->map->height = 0;
	while ((line = get_next_line(fd)))
    {
        t_map->map = realloc(t_map->map, sizeof(char *) * (t_map->map->height + 2));
        if (!t_map->map)
            ft_error("Error\nInvalid map");
        t_map->map[t_map->map->height] = line;
        t_map->map[t_map->map->height + 1] = NULL;
        t_map->map->height++;
    }
    map_check(t_map);
    close(fd);
}
 */
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

