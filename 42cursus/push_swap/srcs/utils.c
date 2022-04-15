/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:32:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:37:23 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	is_sorted(t_stack *a)
{
	t_list	*ptr;

	ptr = a->bottom;
	while (ptr != a->top && ptr->data > ptr->next->data)
		ptr = ptr->next;
	if (ptr == a->top)
		exit(EXIT_SUCCESS);
}

void	precheck(t_stack *a)
{
	t_list	*ptr;
	t_list	*cmp;

	is_sorted(a);
	ptr = a->bottom;
	while (ptr->next != a->bottom)
	{
		cmp = ptr->next;
		while (cmp != ptr)
		{
			if (cmp->data == ptr->data)
				exit_msg();
			cmp = cmp->next;
		}
		ptr = ptr->next;
	}
}

void	value_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
