/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:26:51 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/15 18:04:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*ptr;

	ptr = s;
	if (!s)
		return ;
	while (*ptr)
	{
		write(fd, ptr, 1);
		ptr++;
	}
	write(fd, "\n", 1);
}
