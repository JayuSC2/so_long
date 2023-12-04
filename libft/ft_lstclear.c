/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:51:35 by juitz             #+#    #+#             */
/*   Updated: 2023/11/13 12:38:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current = *lst;
	t_list *next;
	
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
}
/* #include <stdio.h>

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
	int *value_of_node2;
	value_of_node2 = (int*)(second_element->content);
	first_element->next = second_element;
	//ft_lstdelone(second_element, delete_node);

	t_list	*third_element;
	int c = 3;
	void *p_to_content3;
	
	p_to_content3 = &c;
	ft_lstnew(p_to_content3);
	third_element = ft_lstnew(p_to_content3);
	second_element->next = third_element;
	
	ft_lstclear(&second_element, free);
	printf ("%d\n", *value_of_node2);
} */