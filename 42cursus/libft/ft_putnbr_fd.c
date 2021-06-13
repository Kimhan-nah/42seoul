/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:29:15 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/11 19:37:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_print(unsigned int nbr, int fd)
{
	char c;

	if (nbr > 0)
		rec_print(nbr / 10, fd);
	else if (nbr == 0)
		return ;
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	rec_print(nbr, fd);
}
