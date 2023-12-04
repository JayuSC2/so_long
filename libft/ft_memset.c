/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:03:36 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 13:10:20 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int x, size_t len)
{
	unsigned char	*p;

	p = s;
	while (len--)
	{
		*p++ = (unsigned char)x;
	}
	return (s);
}
/*
int	main(void)
{
	char arr[] = "Hello";

	printArray(arr, 5);
	ft_memset(arr, '1', 5);
	printArray(arr, 5);
	return (0);
}
*/