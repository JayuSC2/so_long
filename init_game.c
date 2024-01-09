/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:20 by julian            #+#    #+#             */
/*   Updated: 2024/01/09 15:13:23 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_variables(t_data *data)
{
    data->map->collectibles = 0;
    data->map->exit = 0;
    data->map->x = 0;
    data->map->y = 0;
    data->map->player.is_set = 0;
    data->map->player.moves = 0;
}

void	init_textures(t_data *data)
{
    data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall.xpm", &TEXTURE_SIZE, &TEXTURE_SIZE);
    data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/empty.xpm", &TEXTURE_SIZE, &TEXTURE_SIZE);
    data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/collectible.xpm", &TEXTURE_SIZE, &TEXTURE_SIZE);
    data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm", &TEXTURE_SIZE, &TEXTURE_SIZE);
    data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &TEXTURE_SIZE, &TEXTURE_SIZE);
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
            }
            j++;
        }
        i++;
    }
    if (data->map->player.is_set == 0)
        ft_error("Error\nInvalid map");
}

void	init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    init_textures(data);
    init_player(data);
    mlx_hook(data->win_ptr, 2, 1L << 0, on_keypress, data);
    mlx_hook(data->win_ptr, 17, 1L << 17, on_destroy, data);
    mlx_loop(data->mlx_ptr);
}


