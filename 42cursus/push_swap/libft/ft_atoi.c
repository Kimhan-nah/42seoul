/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:32:04 by hannkim           #+#    #+#             */
/*   Updated: 2021/09/25 17:08:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_lld(unsigned long long res, int sign)
{
	if (res > 9223372036854775807)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return (res * sign);
}

static int	is_valid_ch(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	else if (ch == '+')
		return (2);
	else if (ch == '-')
		return (3);
	else if (ch >= '0' && ch <= '9')
		return (4);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					sign;
	int					count;

	ptr = (char *)s;
	res = 0;
	sign = 1;
	count = 0;
	while (is_valid_ch(*ptr) == 1)
		ptr++;
	if (is_valid_ch(*ptr) == 2 || is_valid_ch(*ptr) == 3)
	{
		if (is_valid_ch(*ptr) == 3)
			sign = -1;
		ptr++;
	}
	while (is_valid_ch(*ptr) == 4 && count < 19)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
		count++;
	}
	res = check_lld(res, sign);
	return (res);
}
