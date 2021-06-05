/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:34:19 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 19:58:38 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	**g_board;
extern int	g_size;

void		print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void		print_board(void)
{
	int		row;
	int		col;
	char	cur;

	row = 0;
	while (row < g_size)
	{
		col = 0;
		while (col < g_size)
		{
			cur = g_board[row][col] + '0';
			write(1, &cur, 1);
			if (col != g_size - 1)
				write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
}
