/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:57:13 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/09 15:47:59 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ret;
	const unsigned char	*s;
	size_t				idx;

	if (!dst && !src)
		return (0);
	ret = (unsigned char *)dst;
	s = (const unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		ret[idx] = s[idx];
		idx++;
	}
	return (ret);
}
