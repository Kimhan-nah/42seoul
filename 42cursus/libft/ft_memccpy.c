/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:55:18 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/09 15:57:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ret;
	const unsigned char	*s;
	size_t				idx;

	ret = (unsigned char *)dst;
	s = (const unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		ret[idx] = s[idx];
		if (s[idx] == (unsigned char)c)
			return (&ret[idx + 1]);
		idx++;
	}
	return (0);
}
