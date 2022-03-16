/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 19:26:00 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	t_stack	*a;

	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (argc <= 1)
		return (EXIT_SUCCESS);
	parsing(argv + 1, a);
	// check sorted or duplicated
	


	// sort
	// compress operation (optional)

	return (EXIT_SUCCESS);
}
