/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:32:43 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/24 17:53:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int index;

	while (size > 0)
	{
		index = 0;
		while (index < size - 1)
		{
			if (tab[index] > tab[index + 1])
				swap(&tab[index], &tab[index + 1]);
			index++;
		}
		size--;
	}
}
