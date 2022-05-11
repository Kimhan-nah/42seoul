/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:04:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/11 18:02:06 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_valid_ch(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					count;

	ptr = (char *)s;
	res = 0;
	count = 0;
	while (is_valid_ch(*ptr) == 1 && count < 19)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
		count++;
	}
	if (*ptr && is_valid_ch(*ptr) == 0)
		return (-1);
	if (res > 2147483647)
		return (0);
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (NULL);
	if (!memset(mem, 0, count * size))
		return (NULL);
	return (mem);
}
