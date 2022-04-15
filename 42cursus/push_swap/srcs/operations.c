/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:21:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, int ab)
{
	t_list	*tmp;

	if (ab == A)
		ft_putstr_fd("sa\n", 1);
	else if (ab == B)
		ft_putstr_fd("sb\n", 1);
	if (stack->len < 2)
		return ;
	tmp = stack->top->prev;
	if (stack->len == 2)
	{
		stack->bottom = stack->top;
		stack->top = tmp;
	}
	else
	{
		tmp->prev->next = stack->top;
		stack->top->prev = tmp->prev;
		stack->top->next = tmp;
		tmp->prev = stack->top;
		tmp->next = stack->bottom;
		stack->bottom->prev = tmp;
		stack->top = tmp;
	}
}

void	push(t_stack *from, t_stack *to, int ab)
{
	t_list	*top;

	if (from->len < 1)
		return ;
	if (ab == A)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
	top = from->top;
	if (from->top == from->bottom)
	{
		from->top = NULL;
		from->bottom = NULL;
	}
	else
	{
		top->next->prev = top->prev;
		top->prev->next = top->next;
		from->top = top->prev;
	}
	lstadd_back(to, top);
	(from->len)--;
	(to->len)++;
}

void	rotate(t_stack *a, t_stack *b, int ab, int *cnt)
{
	if (ab == A)
	{
		ft_putstr_fd("ra\n", 1);
		a->bottom = a->top;
		a->top = a->bottom->prev;
	}
	else if (ab == B)
	{
		ft_putstr_fd("rb\n", 1);
		b->bottom = b->top;
		b->top = b->bottom->prev;
	}
	else
	{
		ft_putstr_fd("rr\n", 1);
		a->bottom = a->top;
		a->top = a->bottom->prev;
		b->bottom = b->top;
		b->top = b->bottom->prev;
	}
	if (cnt != NULL)
		(*cnt)++;
}

void	reverse(t_stack *a, t_stack *b, int ab)
{
	if (ab == A)
	{
		ft_putstr_fd("rra\n", 1);
		a->bottom = a->bottom->next;
		a->top = a->bottom->prev;
	}
	else if (ab == B)
	{
		ft_putstr_fd("rrb\n", 1);
		b->bottom = b->bottom->next;
		b->top = b->bottom->prev;
	}
	else
	{
		ft_putstr_fd("rrr\n", 1);
		a->bottom = a->bottom->next;
		a->top = a->bottom->prev;
		b->bottom = b->bottom->next;
		b->top = b->bottom->prev;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, AB);
	swap(b, AB);
	ft_putstr_fd("ss\n", 1);
}
