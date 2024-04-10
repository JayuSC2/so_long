/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraydup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:14:29 by juitz             #+#    #+#             */
/*   Updated: 2024/04/10 16:06:45 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarraydup(char **strarray)
{
	char **strarraydup;
	int i;
	int rows;
	
	i = 0;
	while (strarray[i])
		i++;
	rows = i;
	strarraydup = (char **)malloc((rows+ 1) * sizeof(char *));
	if (!strarraydup)
		return (NULL);
	i = 0;
	while (strarray[i])
	{
		//ft_printf("%s\n", strarray[i]);
		strarraydup[i] = ft_strdup(strarray[i]);
		if (!strarraydup[i])
			return (ft_free(strarraydup), NULL);
		ft_printf("%s\n", strarraydup[i]);
		i++;
	}
	strarraydup[i] = NULL;
	return (strarraydup);
}