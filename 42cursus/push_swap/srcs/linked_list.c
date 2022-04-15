/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:18:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 16:08:10 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstadd_front(t_stack *stack, t_list *new_list)
{
	if (stack->bottom == NULL)
	{
		stack->bottom = new_list;
		stack->top = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = stack->top;
	new_list->next = stack->bottom;
	stack->bottom = new_list;
	new_list->next->prev = new_list;
	new_list->prev->next = new_list;
}

void	lstadd_back(t_stack *stack, t_list *new_list)
{
	if (stack->bottom == NULL)
	{
		stack->bottom = new_list;
		stack->top = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = stack->top;
	new_list->next = stack->bottom;
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

void	lstprint(t_list *top)
{
	t_list	*ptr;

	ptr = top;
	if (top == NULL)
		return ;
	while (ptr->prev != top)
	{
		printf("%d ", ptr->data);
		ptr = ptr->prev;
	}
	printf("%d\n", ptr->data);
}

// 지우기
void	stackprint(t_stack *a, t_stack *b)
{
	printf("A : ");
	lstprint(a->top);
	printf("\n");
	printf("B : ");
	lstprint(b->top);
	printf("\n\n");
}
