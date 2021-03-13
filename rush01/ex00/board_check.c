/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:34:08 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 19:58:43 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	**g_board;
extern int	g_size;

int		is_duplicate(int row, int col, int input)
{
	int i;

	i = -1;
	while (++i < g_size)
	{
		if (g_board[i][col] == input && i != row)
			return (1);
	}
	i = -1;
	while (++i < g_size)
	{
		if (g_board[row][i] == input && i != col)
			return (1);
	}
	return (0);
}

int		up_valid(int val, int col)
{
	int i;
	int max;
	int cnt;

	i = -1;
	max = 0;
	cnt = 0;
	while (++i < g_size)
	{
		if (g_board[i][col] == 0)
			return (1);
		else if (g_board[i][col] > max)
		{
			cnt++;
			max = g_board[i][col];
		}
	}
	if (cnt == val)
		return (1);
	else
		return (0);
}

int		down_valid(int val, int col)
{
	int i;
	int max;
	int cnt;

	i = g_size;
	max = 0;
	cnt = 0;
	while (--i >= 0)
	{
		if (g_board[i][col] == 0)
			return (1);
		else if (g_board[i][col] > max)
		{
			cnt++;
			max = g_board[i][col];
		}
	}
	if (cnt == val)
		return (1);
	else
		return (0);
}

int		left_valid(int val, int row)
{
	int i;
	int max;
	int cnt;

	i = -1;
	max = 0;
	cnt = 0;
	while (++i < g_size)
	{
		if (g_board[row][i] == 0)
			return (1);
		else if (g_board[row][i] > max)
		{
			cnt++;
			max = g_board[row][i];
		}
	}
	if (cnt == val)
		return (1);
	else
		return (0);
}

int		right_valid(int val, int row)
{
	int i;
	int max;
	int cnt;

	i = g_size;
	max = 0;
	cnt = 0;
	while (--i >= 0)
	{
		if (g_board[row][i] == 0)
			return (1);
		else if (g_board[row][i] > max)
		{
			cnt++;
			max = g_board[row][i];
		}
	}
	if (cnt == val)
		return (1);
	else
		return (0);
}
