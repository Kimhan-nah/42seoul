/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:17:50 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/13 23:38:46 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		nb_count(int nb)
{
	int count;

	count = 1;
	while (nb > 9)
	{
		count *= 10;
		nb /= 10;
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	int		count;
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	count = nb_count(nb);
	while (count > 0)
	{
		c = nb / count + '0';
		write(1, &c, 1);
		nb %= count;
		count /= 10;
	}
}
