/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/02 18:44:41 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg(char *str)
{
	write(2, "Error : ", 9);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int		is_sorted(t_stack *a)
{
	t_list	*ptr;

	ptr = a->head;
	while (ptr->data < ptr->next->data && ptr != a->head->prev)
		ptr = ptr->next;
	if (ptr == a->head->prev)		// sorted
		return (1);
	return (0);
}

void	precheck(t_stack *a)
{
	t_list	*ptr;
	t_list	*cmp;

	// check sorted
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
	ptr = a->head;

	// check duplicated
	while (ptr->next != a->head)
	{
		cmp = ptr->next;
		while (cmp != ptr)
		{
			if (cmp->data == ptr->data)
				exit_msg("Duplicated!");
			cmp = cmp->next;
		}
		ptr = ptr->next;
	}
}

int main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	stacks = (t_stacks *)ft_calloc(1, sizeof(t_stacks));
	parsing(argv + 1, stacks->a);
	precheck(stacks->a);

	// sort
	
	// compress operation (optional)

	return (EXIT_SUCCESS);
}
