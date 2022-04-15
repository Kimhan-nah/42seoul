/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:14:39 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:35:39 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	division_b(t_stack *a, t_stack *b, int min, int max)
{
	int	mid_a;
	int	mid_b;
	int	size;
	int	cnt[2];

	mid_b = (min + max) / 2;
	mid_a = (mid_b + max) / 2;
	size = max - min + 1;
	ft_memset(cnt, 0, sizeof(int) * 2);
	while (size > 0)
	{
		if (b->top->idx < mid_b)
			rotate(a, b, B, cnt + 1);
		else
		{
			push(b, a, A);
			if (a->top->idx < mid_a)
				rotate(a, b, A, cnt);
		}
		size--;
	}
	rollback(a, b, cnt, B);
	return (cnt[0]);
}

void	b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	int	mid_a;
	int	mid_b;
	int	size;
	int	ra;

	mid_b = (min + max) / 2;
	mid_a = (mid_b + max) / 2;
	size = max - min + 1;
	if (size <= 3)
	{
		small_sort_b(a, b, size);
		return ;
	}
	ra = division_b(a, b, min, max);
	a_to_b(a, b, mid_a, max);
	while (ra > 0)
	{
		reverse(a, b, A);
		ra--;
	}
	a_to_b(a, b, mid_b, mid_a - 1);
	b_to_a(a, b, min, mid_b - 1);
}
