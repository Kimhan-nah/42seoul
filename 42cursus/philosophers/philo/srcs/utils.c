/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:04:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 15:24:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			idx;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		exit_msg("fail malloc\n");
	idx = 0;
	while (idx < count * size)
	{
		mem[idx] = 0;
		idx++;
	}
	return (mem);
}

void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;

	ptr = s;
	if (fd < 0 || !s)
		return ;
	while (*ptr)
	{
		write(fd, ptr, 1);
		ptr++;
	}
}

void	exit_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
