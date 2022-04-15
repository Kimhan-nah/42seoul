/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:32:04 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 19:01:52 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/push_swap.h"

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
	else if (ch == 0)
		return (5);
	else
		exit_msg();
	return (0);
}

static int	check(unsigned long long res, int sign, const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (is_valid_ch(*ptr) == 1)
		ptr++;
	if (res == 0)
	{
		if (is_valid_ch(*ptr) == 2 || is_valid_ch(*ptr) == 3)
			ptr++;
		if (*ptr == 0)
			exit_msg();
		if (is_valid_ch(*ptr) == 2 || is_valid_ch(*ptr) == 3)
			exit_msg();
	}
	if (res > 2147483647)
	{
		if (sign < 0 && res == 2147483648)
			return (res * sign);
		else
			exit_msg();
	}
	return (res * sign);
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
	return (check(res, sign, s));
}
