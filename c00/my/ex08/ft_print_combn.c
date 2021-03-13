/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:54:26 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/10 02:56:44 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	rec_comb(char *arr, int index, int n, char *max);
void	ft_putchar(int n, char *arr, char *max);
int		is_max(char *arr, int n, char *max);

void	ft_print_combn(int n)
{
	char	arr[n];
	char	max[n];
	int		i;

	arr[0] = '0';
	i = 0;
	if (n == 1)
	{
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
		return ;
	}
	while (i < n)
	{
		max[i] = (10 - n + i) + '0';
		i++;
	}
	while (arr[0] <= max[0])
	{
		rec_comb(arr, 1, n, max);
		arr[0]++;
	}
}

void	rec_comb(char *arr, int index, int n, char *max)
{
	arr[index] = arr[index - 1] + 1;
	while (arr[index] <= max[index])
	{
		if (index < n - 1)
			rec_comb(arr, index + 1, n, max);
		else
			ft_putchar(n, arr, max);
		arr[index]++;
	}
}

void	ft_putchar(int n, char *arr, char *max)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &arr[i], 1);
		i++;
	}
	if (!is_max(arr, n, max))
		write(1, ", ", 2);
}

int		is_max(char *arr, int n, char *max)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (arr[i] != max[i])
			return (0);
		i++;
	}
	return (1);
}
