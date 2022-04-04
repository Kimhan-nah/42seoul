/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:21:47 by hannah            #+#    #+#             */
/*   Updated: 2022/04/04 14:31:14 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa, sb, ss
void	swap(t_stack *stack)
{
	t_list	*tmp;
	t_list *top;

	if (stack->len < 2)
		return ;
	tmp = stack->top;
	top = tmp->prev;

	stack->top = top;
	top->prev->next = tmp;

	tmp->prev = top->prev;
	tmp->next = top;

	top->prev = tmp;
	top->next = stack->head;
}

// pa, pb
void	push(t_stack *from, t_stack *to)
{
	t_list	*top;

	if (from->len < 1)
		return ;
	top = from->top;

	if (top == from->head)
		from->head = NULL;
	else
	{
		top->next->prev = top->prev;
		top->prev->next = top->next;
	}
	top->next = to->head;
	top->prev = to->top;
	lstadd_back(to, top);
	(from->len)--;
	(to->len)++;
}

// ra, rb, rr
void	rotate(t_stack *stack)
{
	stack->head = stack->top;
}

// rra, rrb, rrr
void	reverse(t_stack *stack)
{
	stack->head = stack->head->next;
}
