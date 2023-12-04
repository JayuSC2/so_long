/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:15 by juitz             #+#    #+#             */
/*   Updated: 2023/11/09 15:47:56 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{	
	int i;
	
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	t_list	*first_element;
	int a = 1;
	void *p_to_content1;
	
	p_to_content1 = &a;
	first_element = ft_lstnew(p_to_content1);
	
	t_list	*second_element;
	int b = 2;
	void *p_to_content2;
	
	p_to_content2 = &b;
	ft_lstnew(p_to_content2);
	second_element = ft_lstnew(p_to_content1);
	first_element->next = second_element;

	t_list	*third_element;
	int c = 3;
	void *p_to_content3;
	
	p_to_content3 = &c;
	ft_lstnew(p_to_content3);
	third_element = ft_lstnew(p_to_content3);
	second_element->next = third_element;
	
	t_list *empty_list = NULL;
	
	printf("Number of Nodes: %d", ft_lstsize(empty_list));
	// t_list	*third_element;
	
}