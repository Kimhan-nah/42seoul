/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:48 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:45:10 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_data(t_stack *a, int *arr)
{
	t_list	*ptr;
	int		i;

	ptr = a->bottom;
	i = 0;
	while (i < a->len)
	{
		while (ptr->data != arr[i])
			ptr = ptr->next;
		ptr->data = i;
		printf("i : %d, ptr->data :  %d\n",i, ptr->data);
		i++;
	}
}

static void	value_swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int idx_pivot;
	int pivot;
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
	int q;

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
	int		*tmp;
	int		i;

	ptr = a->bottom;
	tmp = (int *)ft_calloc(a->max, sizeof(int));
	i = 0;
	while (i < a->len)
	{
		tmp[i] = ptr->data;
		i++;
		ptr = ptr->next;
	}

	quick_sort(tmp, 0, a->max);

	i = 0;

	set_data(a, tmp);
//	lstprint(a->bottom);
//	printf("======\n");
	free(tmp);
}

void	parsing(char **argv, t_stack *a)
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
			lstadd_front(a, lstnew(data));
			j++;
			(a->len)++;
		}
		free(tmp);
		i++;
	}
	a->max = a->len - 1;
	indexing(a);
}
