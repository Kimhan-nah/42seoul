/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:26:02 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/08 19:03:07 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*buf;
	size_t				idx;

	buf = (const unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		idx = 0;
		while (idx < len)
		{
			((unsigned char *)dst)[idx] = buf[idx];
			idx++;
		}
	}
	else
	{
		idx = len;
		while (idx > 0)
		{
			((unsigned char *)dst)[idx - 1] = buf[idx - 1];
			idx--;
		}
	}
	return (dst);
}
