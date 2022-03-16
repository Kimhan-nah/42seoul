/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 15:19:54 by hannkim          ###   ########.fr       */
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
	t_list	a;
	t_list	b;
	
	if (argc <= 1)
		return (EXIT_SUCCESS);
	parsing(argv + 1, &a);
	// check sorted or duplicated
	// sort
	// compress operation (optional)

	return (EXIT_SUCCESS);
}
