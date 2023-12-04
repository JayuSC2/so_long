
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*first_element;

	first_element = malloc(sizeof(t_list));
	if (!first_element)
		return (NULL);
	first_element->content = content;
	first_element->next = NULL;
	return (first_element);
}

/* #include <stdio.h>
int main()
{
	int value = 1; 
	void *p_to_content;
	p_to_content = &value; 

	t_list *my_very_first_element;

	my_very_first_element = ft_lstnew(p_to_content);
	int *value_of_node;
	value_of_node = (int*)(my_very_first_element->content);
	// printf("%d\n",*value_of_node);

	t_list *my_second_element;
	
	int b = 2;
	void *p_to_content2;
	p_to_content2 = &b;
	
	my_second_element = ft_lstnew(p_to_content2);
	int *value_of_node2;
	value_of_node2 = (int*)(my_second_element->content);
	//printf("%d\n", *value_of_node2);
	//printf("Next is: %p", my_second_element->next);
	//printf("\nAdress of second element is %p\n", my_second_element);
	my_very_first_element->next = my_second_element;
	// printf("Next from first is :%p\n", my_very_first_element->next);
	t_list *i_want_to_be_second_element; 
	i_want_to_be_second_element = my_very_first_element->next;
	// printf("%d\n",*value_of_node2);

	t_list *my_third_element;

	int c = 3;
	void *p_to_content3;
	p_to_content3 = &c;

	my_third_element = ft_lstnew(p_to_content3);
	int *value_of_node3;
	value_of_node3 = (int*)(my_third_element->content);
	// my_second_element->next = my_third_element;
	// printf("%d\n", *value_of_node3);

	// t_list *i_want_to_be_second_element;
	// i_want_to_be_second_element = my_very_first_element->next;
	// t_list *i_want_to_be_third_element;
	// i_want_to_be_third_element = my_second_element->next;

	t_list **lst;
	lst =&my_very_first_element; 
	ft_lstadd_front(lst, my_third_element);
	while (*lst != NULL)
	{
		int *value;
		t_list *current_element;
		current_element = *lst;
		value= (int *)(current_element->content);
		printf("%d \n", *value);
		*lst = current_element->next;
		printf("next element is %p\n", current_element->next);
	} 
	//printf("%c", my_)

} */
