/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:43:32 by juitz             #+#    #+#             */
/*   Updated: 2024/04/10 15:53:36 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **strarray)
{
	int	i;

	i = 0;
	if (strarray == NULL)
		return ;
	while (strarray[i])
		free(strarray[i++]);
	free(strarray);
}