/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:17:34 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/18 23:08:20 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ft_atoi_base(char *str, char *base);
extern int	is_valid_base(char *base, int b_len);
extern int	len_base(char *base);

char		*ft_itoa(char *ret, char *base_to, int nbr, int rt_len)
{
	unsigned int	nb;
	int				r_idx;
	int				b_len;

	b_len = len_base(base_to);
	if (nbr < 0)
	{
		ret[0] = '-';
		r_idx = rt_len;
		nb = nbr * -1;
	}
	else
	{
		nb = nbr;
		r_idx = rt_len - 1;
	}
	if (nb == 0)
		ret[0] = base_to[0];
	while (nb > 0)
	{
		ret[r_idx] = base_to[nb % b_len];
		nb /= b_len;
		r_idx--;
	}
	return (ret);
}

char		*ret_alloc(char *base_to, int nbr)
{
	unsigned int	nb;
	int				rt_len;
	int				b_len;
	char			*ret;

	rt_len = 0;
	b_len = len_base(base_to);
	if (nbr < 0)
		nb = nbr * -1;
	else
		nb = nbr;
	while (nb > 0)
	{
		nb /= b_len;
		rt_len++;
	}
	if (!(ret = (char *)malloc(rt_len + 1)))
		return (0);
	ret = ft_itoa(ret, base_to, nbr, rt_len);
	return (ret);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*ret;

	if (!is_valid_base(base_from, len_base(base_from))
			|| !is_valid_base(base_to, len_base(base_to)))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	ret = ret_alloc(base_to, nb);
	return (ret);
}
