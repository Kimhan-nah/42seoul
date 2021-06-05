/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:11:27 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/13 23:21:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len_base(char *base)
{
	int	len;

	len = 0;
	while (*base)
	{
		len++;
		base++;
	}
	return (len);
}

int		len_nbr(int nbr, int b_len)
{
	int len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= b_len;
		len++;
	}
	return (len - 1);
}

void	rec_parse(int nbr, char *base, int b_len, int n_len)
{
	char	ch;

	ch = base[nbr % b_len];
	if (n_len > 0)
		rec_parse(nbr / b_len, base, b_len, n_len - 1);
	write(1, &ch, 1);
}

int		is_valid_base(char *base, int b_len)
{
	char *ptr1;
	char *ptr2;

	ptr1 = base;
	ptr2 = base;
	if (b_len <= 1)
		return (0);
	while (*ptr1)
	{
		if (*ptr1 == '+' || *ptr1 == '-')
			return (0);
		while (*ptr2)
		{
			if (*ptr1 == *ptr2 && ptr1 != ptr2)
				return (0);
			ptr2++;
		}
		ptr2 = base;
		ptr1++;
	}
	return (1);
}

int		ft_atoi_base(int nbr, char *base)
{
	int				b_len;
	int				n_len;
	unsigned int	nb;

	b_len = len_base(base);
	if (is_valid_base(base, b_len))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nb = nbr * (-1);
		}
		else
			nb = nbr;
		n_len = len_nbr(nb, b_len);
		rec_parse(nb, base, b_len, n_len);
	}
	return (res);
}
