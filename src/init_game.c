/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:20 by julian            #+#    #+#             */
/*   Updated: 2024/01/11 17:08:41 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_variables(t_data *data)
{
    data->map->collectibles = 0;
    data->map->exit = 0;
    data->map->player.x = 0;
    data->map->player.y = 0;
    data->map->player.is_set = 0;
    data->map->player.moves = 0;
}

void	init_textures(t_data *data)
{
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/walls/wall.xpm", TEXTURE_WIDTH, TEXTURE_HEIGHT);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor/floors.xpm", TEXTURE_WIDTH, TEXTURE_HEIGHT);
    data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/collectibles/chest_01_0.xpm", TEXTURE_WIDTH, TEXTURE_HEIGHT);
    data->exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exits/exit_closed.xpm", TEXTURE_WIDTH, TEXTURE_HEIGHT);
    data->player_front = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/characters/player_front.xpm", TEXTURE_WIDTH, TEXTURE_HEIGHT);
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

