/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:40:00 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/07 22:29:16 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb(void);
void	ft_a_10(int a_100, int a_10);
void	ft_a_1(int a_100, int a_10, int a_1);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int a_100;
	int a_10;
	int a_1;

	a_100 = 0;
	a_10 = 0;
	a_1 = 0;
	while (a_100 <= 7)
	{
		ft_a_10(a_100, a_100 + 1);
		a_100++;
	}
}

void	ft_a_10(int a_100, int a_10)
{
	while (a_10 <= 8)
	{
		ft_a_1(a_100, a_10, a_10 + 1);
		a_10++;
	}
}

void	ft_a_1(int a_100, int a_10, int a_1)
{
	while (a_1 <= 9)
	{
		ft_putchar(a_100 + '0');
		ft_putchar(a_10 + '0');
		ft_putchar(a_1 + '0');
		if (a_100 == 7 && a_10 == 8 && a_1 == 9)
			return ;
		else
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		a_1++;
	}
}
