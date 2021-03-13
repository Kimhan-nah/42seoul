/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:36:19 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/12 02:46:32 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int j;

	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == 0)
		return (0);
	i = 0;
	j = min;
	while (i < max - min)
	{
		arr[i] = j;
		i++;
		j++;
	}
	return (arr);
}
