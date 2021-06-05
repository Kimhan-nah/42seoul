/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:30:57 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/06 18:31:41 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb2(void);
void	ft_print_comb2_1(int a, int a_10, int a_1);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int a_10;
	int a_1;

	a = 0;
	while (a < 99)
	{
		a_10 = a / 10;
		a_1 = a % 10;
		ft_print_comb2_1(a, a_10, a_1);
		a++;
	}
}

void	ft_print_comb2_1(int a, int a_10, int a_1)
{
	int b;
	int b_10;
	int b_1;

	b = a + 1;
	while (b < 100)
	{
		b_10 = b / 10;
		b_1 = b % 10;
		ft_putchar(a_10 + '0');
		ft_putchar(a_1 + '0');
		ft_putchar(' ');
		ft_putchar(b_10 + '0');
		ft_putchar(b_1 + '0');
		if (a == 98 && b == 99)
			return ;
		else
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		b++;
	}
}
