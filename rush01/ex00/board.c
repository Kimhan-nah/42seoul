/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:33:55 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 20:01:09 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern void	recursive_solve(int row, int col, int input);
extern int	**g_condition;
extern int	g_size;
int			**g_board;

int			process_for_one(int i, int j)
{
	int fix;
	int row;
	int col;

	fix = i % 2 ? g_size - 1 : 0;
	if (i < 2)
	{
		row = fix;
		col = j;
	}
	else
	{
		row = j;
		col = fix;
	}
	if (g_board[row][col] != 0 && g_board[row][col] != g_size)
		return (0);
	else
		g_board[row][col] = g_size;
	return (1);
}

int			process_for_n(int i, int j)
{
	int row;
	int col;
	int k;
	int fix;

	k = -1;
	while (++k < g_size)
	{
		fix = i % 2 ? g_size - k : k + 1;
		if (i < 2)
		{
			row = k;
			col = j;
		}
		else
		{
			row = j;
			col = k;
		}
		if (g_board[row][col] != 0 && g_board[row][col] != fix)
			return (0);
		else
			g_board[row][col] = fix;
	}
	return (1);
}

int			pre_process(void)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < g_size)
		{
			if (g_condition[i][j] == g_size)
			{
				if (!process_for_n(i, j))
					return (0);
			}
			else if (g_condition[i][j] == 1)
			{
				if (!process_for_one(i, j))
					return (0);
			}
		}
	}
	recursive_solve(0, 0, 0);
	return (1);
}

void		free_allocations(void)
{
	int i;

	if (g_condition)
	{
		i = 0;
		while (i < 4)
		{
			free(g_condition[i]);
			i++;
		}
		free(g_condition);
		g_condition = 0;
	}
	if (g_board)
	{
		i = 0;
		while (i < g_size)
		{
			free(g_board[i]);
			i++;
		}
		free(g_board);
		g_board = 0;
	}
}

int			init_board(void)
{
	int i;
	int j;

	g_board = (int **)malloc(sizeof(int *) * g_size);
	i = -1;
	while (++i < g_size)
		g_board[i] = (int *)malloc(sizeof(int) * g_size);
	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
			g_board[i][j] = 0;
	}
	if (!pre_process())
		return (0);
	return (1);
}
