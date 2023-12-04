/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:40 by juitz             #+#    #+#             */
/*   Updated: 2023/11/09 17:27:07 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return(lst);
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
	first_element->next = second_element;

	t_list	*third_element;
	int c = 3;
	void *p_to_content3;
	
	p_to_content3 = &c;
	ft_lstnew(p_to_content3);
	third_element = ft_lstnew(p_to_content3);
	second_element->next = third_element;
	
	t_list *last_element;
	last_element = ft_lstlast(first_element);
	int *value;
	value = (int *)last_element->content;
	printf("I am node at adress :%p, my content is %d, and i am pointing to %p", last_element,*value, last_element->next);
} */
