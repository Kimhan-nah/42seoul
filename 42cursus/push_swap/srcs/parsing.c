/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:48 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 15:55:17 by hannkim          ###   ########.fr       */
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
		printf("\n========arr[%d] : %d=======\n", i, arr[i]);

		ptr = a->bottom;
		while (ptr->data != arr[i])
		{
			printf("ptr->data : %d\n", ptr->data);
			ptr = ptr->next;
		}
		printf("ptr->data : %d\n", ptr->data);
		if (ptr)
		ptr->idx = i;
		printf("----PTR DATA %d---\n",  ptr->data);
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

//	int i = start;
//	int j = 0;
//	int k = end + 1;

	if (start < end)
	{
//		printf("\n<<<Quick Sort : arr[%d] ~ arr[%d]>>>\n", start, end);
//		while (j < start)
//		{
//			printf("%d ", arr[j]);
//			j++;
//		}
//		while (i <= end)
//		{
//			printf("%d ", arr[i]);
//			i++;
//		}
//		while (k <= 9)
//		{
//			printf("%d ", arr[k]);
//			k++;
//		}
		printf("\n");

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

	printf("INDEXING : a->max is %d\n", a->max);
	i = 0;
	while (i < a->len)
	{
		printf("%d ", arr[i]);
		i++;
	}

	set_data(a, arr);

	printf("\nSET DATA\n");
	lstprint(a->bottom);

	free(arr);
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
