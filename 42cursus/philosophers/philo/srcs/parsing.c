/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 15:28:19 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

static int	ft_atoi(const char *s)
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

void	parsing(char **argv)
{
	t_info *info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
}
