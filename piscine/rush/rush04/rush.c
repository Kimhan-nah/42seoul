/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:43:13 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/20 23:09:07 by hannkim          ###   ########.fr       */
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
			if( (row == 0 && col == 0) || (row == y-1 && col == x-1 && row != 0 && col != 0))
				ft_putchar('A');
			else if((row == 0 && col == x-1) || (row == y-1 && col == 0))
			    ft_putchar('C');
			else if(row > 0 && row < y-1 && col > 0 && col < x-1)
				ft_putchar(' ');
			else
				ft_putchar('B');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
