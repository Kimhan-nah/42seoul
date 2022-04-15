/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:35 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:47:33 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rollback(t_stack *a, t_stack *b, int *cnt, int ab)
{
	while (cnt[1] > 0)
	{
		reverse(a, b, B);
		cnt[1]--;
	}
	while (ab == A && cnt[0] > 0)
	{
		reverse(a, b, A);
		cnt[0]--;
	}
}

static void	division_a(t_stack *a, t_stack *b, int min, int max)
{
	int	mid_a;
	int	mid_b;
	int	size;
	int	cnt[2];

	mid_a = (min + max) / 2;
	mid_b = (min + mid_a) / 2;
	size = max - min + 1;
	ft_memset(cnt, 0, sizeof(int) * 2);
	while (size > 0)
	{
		if (a->top->idx > mid_a)
			rotate(a, b, A, cnt);
		else
		{
			push(a, b, B);
			if (b->top->idx > mid_b)
				rotate(a, b, B, cnt + 1);
		}
		size--;
	}
	rollback(a, b, cnt, A);
}

void	a_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	mid_a;
	int	mid_b;
	int	size;

	mid_a = (min + max) / 2;
	mid_b = (min + mid_a) / 2;
	size = max - min + 1;
	if (size <= 3)
	{
		small_sort_a(a, b, size);
		return ;
	}
	division_a(a, b, min, max);
	a_to_b(a, b, mid_a + 1, max);
	b_to_a(a, b, mid_b + 1, mid_a);
	b_to_a(a, b, min, mid_b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		three_sort(a, b, 0, 1);
	else if (a->len == 3)
		three_sort(a, b, 0, 2);
	else if (a->len <= 5)
		five_sort(a, b, a->len);
	else
		a_to_b(a, b, 0, a->max);
}
