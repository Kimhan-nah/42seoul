/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:34:23 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 20:01:14 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			g_find_flag = 0;
extern int	**g_board;
extern int	**g_condition;
extern int	g_size;
extern int	is_duplicate(int row, int col, int input);
extern void	print_board(void);
extern int	up_valid(int val, int col);
extern int	down_valid(int val, int col);
extern int	left_valid(int val, int row);
extern int	right_valid(int val, int row);

int			board_check(int row, int col, int input)
{
	int i;

	i = -1;
	if (is_duplicate(row, col, input))
		return (0);
	while (++i < g_size)
	{
		if (!up_valid(g_condition[0][i], i))
			return (0);
		if (!down_valid(g_condition[1][i], i))
			return (0);
		if (!left_valid(g_condition[2][i], i))
			return (0);
		if (!right_valid(g_condition[3][i], i))
			return (0);
	}
	return (1);
}

int			has_zero(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (g_board[i][j] == 0)
				return (1);
		}
	}
	return (0);
}

int			is_find(void)
{
	if (!has_zero())
	{
		print_board();
		g_find_flag = 1;
		return (1);
	}
	return (0);
}

void		recursive_solve(int row, int col, int input)
{
	int nx;
	int ny;

	if (row == g_size || g_find_flag)
		return ;
	nx = (col == g_size - 1) ? row + 1 : row;
	ny = (col == g_size - 1) ? 0 : col + 1;
	if (g_board[row][col] != 0)
	{
		recursive_solve(nx, ny, 0);
		return ;
	}
	while (++input <= g_size)
	{
		g_board[row][col] = input;
		if (board_check(row, col, input))
		{
			if (is_find())
				return ;
			recursive_solve(nx, ny, 0);
		}
		else
			g_board[row][col] = 0;
	}
	g_board[row][col] = 0;
}
