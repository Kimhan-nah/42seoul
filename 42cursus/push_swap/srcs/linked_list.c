/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:18:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/03 16:42:18 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//int		is_empty(t_stack *stack)
//{
//	if (stack->len > 0)
//		return (1);
//	return (0);
//}

void	lstadd_back(t_stack *stack, t_list *new_list)
{
	if (stack->head == NULL)
	{
		stack->head = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = stack->head->prev;
	new_list->next = stack->head;
	stack->head->prev = new_list;
	new_list->prev->next = new_list;
}

t_list	*lstnew(int data)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	list->data = data;
	list->next = list;
	list->prev = list;
	return (list);
}

void	lstprint(t_list *head)
{
	t_list	*ptr;

	ptr = head;
	while (ptr->next != head)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);

}
