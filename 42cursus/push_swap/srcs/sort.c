/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:35 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 16:26:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b, int min, int max);
static void b_to_a(t_stack *a, t_stack *b, int min, int max);

static void	small_sort_b(t_stack *a, t_stack *b, int size)
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
		rotate(a, b, B);
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

static void	small_sort_a(t_stack *a, t_stack *b, int size)
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
		rotate(a, b, A);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
		reverse(a, b, A);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
}

static void b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	int mid_a;
	int mid_b;
	int	size;
	int	ra;
	int	rb;

	mid_b = (min + max) / 2;
	mid_a = (mid_b + max) / 2;
	size = max - min + 1;
	ra = 0;
	rb = 0;
	if (size <= 3)
	{
		small_sort_b(a, b, size);
		return ;
	}
	while (size > 0)
	{
		if (b->top->idx < mid_b)
		{
			rotate(a, b, B);
			rb++;
		}
		else
		{
			push(b, a, A);
			if (a->top->idx < mid_a)
			{
				rotate(a, b, A);
				ra++;
			}
		}
		size--;
	}
	while (rb > 0)
	{
		reverse(a, b, B);
		rb--;
	}
	a_to_b(a, b, mid_a, max);
	while (ra > 0)
	{
		reverse(a, b, A);
		ra--;
	}
	a_to_b(a, b, mid_b, mid_a - 1);
	b_to_a(a, b, min, mid_b - 1);
}

static void	a_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int mid_a;
	int mid_b;
	int	size;
	int	ra;
	int rb;

	mid_a = (min + max) / 2;
	mid_b = (min + mid_a) / 2;
	size = max - min + 1;
	ra = 0;
	rb = 0;
	if (size <= 3)
	{
		small_sort_a(a, b, size);
		return ;
	}
	while (size > 0)
	{
		if (a->top->idx > mid_a)
		{
			rotate(a, b, A);
			ra++;
		}			
		else
		{
			push(a, b, B);
			if (b->top->idx > mid_b)
			{
				rotate(a, b, B);
				rb++;
			}
		}
		size--;
	}
	while (ra > 0)
	{
		reverse(a, b, A);
		ra--;
	}
	while (rb > 0)
	{
		reverse(a, b, B);
		rb--;
	}
	a_to_b(a, b, mid_a + 1, max);
	b_to_a(a, b, mid_b + 1, mid_a);
	b_to_a(a, b, min, mid_b);
}

static void	three_sort(t_stack *a, t_stack *b, int min, int max)
{
	int size;

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
			rotate(a, b, A);
			return ;
		}
		while (a->bottom->idx != max)
			rotate(a, b, A);
		if (a->top->idx > a->top->prev->idx)
			swap(a, A);
	}
}

static void	five_sort(t_stack *a, t_stack *b, int size)
{
	int pivot;
	int	i;

	pivot = size / 2;
	i = 0;
	while (i < size)
	{
		if (a->top->idx < pivot)
			push(a, b, B);
		else
			rotate(a, b, A);
		i++;
	}
	three_sort(a, b, 2, size - 1);
	push(b, a, A);
	push(b, a, A);
	if (a->top->idx > a->top->prev->idx)
		swap(a, A);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		three_sort(a, b, 0, 2);
	else if (a->len <= 5)
		five_sort(a, b, a->len);
	else
		a_to_b(a, b, 0, a->max);
}
