/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:43:13 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/20 23:21:34 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void rush(int x, int y)
{
	int col = 0;
	int row = 0;

	while (row < y && x > 0 && y > 0) 
	{
		col = 0;
		while (col < x)
		{
			if (col > 0 && col < x - 1)
			{
				if (row > 0  && row < y - 1)
					ft_putchar(' ');
				else
					ft_putchar('-');
			}
			else
			{
				if (row > 0 && row < y - 1)
					ft_putchar('|');
				else
					ft_putchar('o');
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
