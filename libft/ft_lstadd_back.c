/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:55 by juitz             #+#    #+#             */
/*   Updated: 2023/11/10 09:16:56 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_element;
	last_element = ft_lstlast(*lst);
	last_element->next = new;
}
/* int	main(void)
{
	
	t_list *first_element;
	int a = 1;
	void *p_to_content2 = &a;
	first_element = ft_lstnew(p_to_content2);
	first_element

	t_list *last_element;
	int c = 3;
	void *p_to_content1= &c;
	last_element = ft_lstnew(p_to_content1);
	ft_lstadd_back(first_element, last_element);

	t_list *second_element;
	int b = 2;
	void *p_to_content3 = &b;
	second_element = ft_lstnew(p_to_content3);

	printf()

	
	
} */