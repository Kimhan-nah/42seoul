/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:32:23 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:36:55 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
	else if (size == 3)
	{
		if (a->top->idx == 0 && a->bottom->idx == 1)
		{
			swap(a, A);
			rotate(a, b, A, NULL);
			return ;
		}
		while (a->bottom->idx != max)
			rotate(a, b, A, NULL);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
}

void	five_sort(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	i;

	pivot = size / 2;
	i = 0;
	while (i < size)
	{
		if (a->top->idx < pivot)
			push(a, b, B);
		else
			rotate(a, b, A, NULL);
		i++;
	}
	three_sort(a, b, 2, size - 1);
	push(b, a, A);
	push(b, a, A);
	if (a->top->idx > a->top->prev->idx)
		swap(a, A);
}

void	small_sort_b(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
	{
		if (b->top->idx < b->top->prev->idx)
			swap(b, B);
	}
	else if (size == 3)
	{
		if (b->top->idx < b->top->prev->idx)
			swap(b, B);
		rotate(a, b, B, NULL);
		if (b->top->idx < b->top->prev->idx)
			swap(b, B);
		reverse(a, b, B);
		if (b->top->idx < b->top->prev->idx)
			swap(b, B);
	}
	while (size > 0)
	{
		push(b, a, A);
		size--;
	}
}

void	small_sort_a(t_stack *a, t_stack *b, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
	else if (size == 3)
	{
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
		rotate(a, b, A, NULL);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
		reverse(a, b, A);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
}
