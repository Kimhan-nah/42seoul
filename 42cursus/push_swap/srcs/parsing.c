/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:48 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:55:42 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_data(t_stack *a, int *arr)
{
	t_list	*ptr;
	int		i;

	i = 0;
	while (i < a->len)
	{
		ptr = a->bottom;
		while (ptr->data != arr[i])
			ptr = ptr->next;
		ptr->idx = i;
		i++;
	}
}

static int	partition(int *arr, int start, int end)
{
	int	idx_pivot;
	int	pivot;
	int	i;

	idx_pivot = start;
	pivot = arr[idx_pivot];
	i = start + 1;
	while (i <= end)
	{
		if (pivot > arr[i])
		{
			idx_pivot++;
			value_swap(arr, idx_pivot, i);
		}
		i++;
	}
	value_swap(arr, idx_pivot, start);
	return (idx_pivot);
}

static void	quick_sort(int *arr, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = partition(arr, start, end);
		quick_sort(arr, start, q - 1);
		quick_sort(arr, q + 1, end);
	}
}

static void	indexing(t_stack *a)
{
	t_list	*ptr;
	int		*arr;
	int		i;

	ptr = a->bottom;
	arr = (int *)ft_calloc(a->len, sizeof(int));
	i = 0;
	while (i < a->len)
	{
		arr[i] = ptr->data;
		i++;
		ptr = ptr->next;
	}
	quick_sort(arr, 0, a->max);
	set_data(a, arr);
	free(arr);
}

void	parsing(char **argv, t_stack *a)
{
	int		i;
	int		j;
	int		data;
	char	**tmp;

	i = 0;
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			data = ft_atoi(tmp[j]);
			lstadd_front(a, lstnew(data));
			free(tmp[j]);
			j++;
			(a->len)++;
		}
		free(tmp);
		i++;
	}
	a->max = a->len - 1;
	indexing(a);
}
