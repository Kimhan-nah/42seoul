/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:24 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 13:14:31 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(int argc, char *argv[])
{
	int		i;
	int		j;
	int		count;
	char	**tmp;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
			j++;
		count += j;
		i++;
		free(tmp);
	}
	return (count);
}

void	parsing(int argc, char *argv[], t_stack *stack)
{
	

}

int main(int argc, char *argv[])
{

//	parsing(argc, argv, a);
	

	return (0);
}
