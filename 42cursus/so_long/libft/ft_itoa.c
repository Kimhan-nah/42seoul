/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:23:49 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/15 17:56:25 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(char *str, int n, int idx)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		str[0] = '-';
	}
	else
	{
		nbr = n;
		idx--;
	}
	while (idx >= 0 && !str[idx])
	{
		str[idx] = nbr % 10 + '0';
		nbr /= 10;
		idx--;
	}
}

static int	ft_len(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		idx;

	idx = ft_len(n);
	str = (char *)ft_calloc(idx + 2, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, idx + 2);
	if (n == 0)
		str[0] = '0';
	else
		putnbr(str, n, idx);
	return (str);
}
