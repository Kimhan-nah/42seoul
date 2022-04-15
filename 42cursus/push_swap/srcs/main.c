/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:58:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	is_sorted(t_stack *a)		// 오름차순 (bottom 가 큰 값이어야 함)
{
	t_list	*ptr;

	ptr = a->bottom;
	while (ptr != a->top && ptr->data > ptr->next->data)
		ptr = ptr->next;
	if (ptr == a->top)		// sorted
		exit(EXIT_SUCCESS);
//		exit_msg();
}

void	precheck(t_stack *a)
{
	t_list	*ptr;
	t_list	*cmp;

	// check sorted
	is_sorted(a);

	// check duplicated
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

	printf("\n\n<<Before Sort!>>\n");
	stackprint(a, b);

	sort(a, b);

	printf("\n\n<<After Sort!>>\n");
	stackprint(a, b);
/// compress operation (optional)
	free(a);
	free(b);

	return (EXIT_SUCCESS);
}
