/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:27:11 by juitz             #+#    #+#             */
/*   Updated: 2024/04/12 15:54:58 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		ft_printf("\nThe %d key (ESC) has been pressed!\n", keysym);
		on_destroy(data);
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	movement(keysym, data);
	close_game(keysym, data);
	return (0);
}
