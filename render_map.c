/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:56:01 by julian            #+#    #+#             */
/*   Updated: 2024/01/09 19:58:26 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map (t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map->full[i])
    {
        j = 0;
        while (data->map->full[i][j])
        {
            if (data->map->full[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            else if (data->map->full[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], j * TEXTURE_WIDTH, i * TEXTURE_HEIGHT);
            j++;
        }
        i++;
    }
    return (0);
}