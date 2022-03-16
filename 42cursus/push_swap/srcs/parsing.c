/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:48 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 15:27:07 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parsing(char **argv, t_list *a)
{
	int		i;
	int		j;
	int		data;
	char	**tmp;

	i = 0;
	while(argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			data = ft_atoi(tmp[j]);
			lstadd_back();
			j++;
		}
		free(tmp);
		i++;
	}


}
