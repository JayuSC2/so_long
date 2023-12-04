/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:18:30 by juitz             #+#    #+#             */
/*   Updated: 2023/11/13 12:29:28 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
#include <stdio.h>

/* void	delete_node(void* content)
{
	printf("Function is called \n");
} */

/* int	main(void)
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
	ft_lstdelone(second_element, delete_node);

	t_list	*third_element;
	int c = 3;
	void *p_to_content3;
	
	p_to_content3 = &c;
	ft_lstnew(p_to_content3);
	third_element = ft_lstnew(p_to_content3);
	second_element->next = third_element;
} */