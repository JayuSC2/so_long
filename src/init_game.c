/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:20 by julian            #+#    #+#             */
/*   Updated: 2024/04/09 17:31:19 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->player_is_set = 1;
                //data->map[i][j] = '0';
                data->player_x = j;
                data->player_y = i;
				ft_printf("%d\n", data->player_is_set);
            }
            j++;
        }
        i++;
    }
    if (data->player_is_set == 0)
        ft_error("Error: no Player found\n");
}

void	count_collectibles(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'C')
            {
                data->collectibles++;
            }
            j++;
        }
        i++;
    }
	ft_printf("%d\n", data->collectibles);
    if (data->collectibles < 1)
        ft_error("Error: Invalid Map, insufficient collectibles");
}

/* void	init_game(t_data *data)
{
	

	init_map(data);
	init_variables(data);
	ft_printf("%s", "test5\n");
} */


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

