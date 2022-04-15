/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 16:23:00 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	is_sorted(t_stack *a)
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

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		exit_msg();
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	parsing(argv + 1, a);
	precheck(a);
	sort(a, b);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}
