/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 06:47:44 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/23 18:39:49 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c);
unsigned int	ch_unsigned_int(int nb);
int				ft_count(unsigned int ch_nb);
void			ft_putnbr(int nb);

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ch_unsigned_int(int nb)
{
	unsigned int ch_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		ch_nb = nb * -1;
	}
	else
		ch_nb = nb;
	return (ch_nb);
}

int				ft_count(unsigned int ch_nb)
{
	int count;

	count = 1;
	while (ch_nb > 9)
	{
		ch_nb /= 10;
		count *= 10;
	}
	return (count);
}

void			ft_putnbr(int nb)
{
	unsigned int	ch_nb;
	int				count;

	ch_nb = ch_unsigned_int(nb);
	count = ft_count(ch_nb);
	while (count > 0)
	{
		ft_putchar(ch_nb / count + '0');
		ch_nb %= count;
		count /= 10;
	}
}
