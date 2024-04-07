/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:20 by julian            #+#    #+#             */
/*   Updated: 2024/04/07 13:36:36 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->map->full = malloc(9 * sizeof(char *));
	data->map->height = 0;
	data->map->width = 0;
}

void    init_variables(t_data *data)
{
    data->map->collectibles = 0;
    data->map->exit = 0;
    data->map->player.x = 0;
    data->map->player.y = 0;
    data->map->player.is_set = 0;
    data->map->player.moves = 0;
}

void	init_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map->full[i])
    {
        j = 0;
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] == 'P')
            {
                data->map->player.is_set = 1;
                data->map->full[i][j] = '0';
                data->map->player.x = j;
                data->map->player.y = i;
				ft_printf("%d\n", data->map->player.is_set);
            }
            j++;
        }
        i++;
    }
    if (data->map->player.is_set == 0)
        ft_error("Error\nInvalid map10");
}

void	init_game(t_data *data)
{
	init_map(data);
	init_variables(data);
}

/* void	fill(char **full_map, t_point size, t_point cur, char fill_char)
{
	//char **full_map;

	//fill_char = data.to_fill;
	//full_map = data.map->full;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || full_map[cur.y][cur.x] != fill_char)
		return;
	full_map[cur.y][cur.x] = 1;
	fill(full_map, size, (t_point){cur.x -1, cur.y}, fill_char);
	fill(full_map, size, (t_point){cur.x +1, cur.y}, fill_char);
	fill(full_map, size, (t_point){cur.x, cur.y -1}, fill_char);
	fill(full_map, size, (t_point){cur.x, cur.y +1}, fill_char);
}

void	fill_map(char **full_map, t_point size, t_point begin)
{
	fill(full_map, size, begin, full_map[begin.x][begin.y]);
}
 */

/* void	init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    init_textures(data);
    init_player(data);
    mlx_hook(data->win_ptr, 2, 1L << 0, on_keypress, data);
    mlx_hook(data->win_ptr, 17, 1L << 17, on_destroy, data);
    mlx_loop(data->mlx_ptr);
}
 */

