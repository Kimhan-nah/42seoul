/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:18:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/04 15:44:20 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstadd_front(t_stack *stack, t_list *new_list)
{
	if (stack->head == NULL)
	{
		stack->head = new_list;
		stack->top = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = stack->top;
	new_list->next = stack->head;

	stack->head = new_list;
	new_list->next->prev = new_list;
	new_list->prev->next = new_list;
}

void	lstadd_back(t_stack *stack, t_list *new_list)
{
	if (stack->head == NULL)
	{
		stack->head = new_list;
		stack->top = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = stack->top;
	new_list->next = stack->head;
	stack->top = new_list;

	new_list->next->prev = new_list;
	new_list->prev->next = new_list;
}

t_list	*lstnew(int data)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
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
