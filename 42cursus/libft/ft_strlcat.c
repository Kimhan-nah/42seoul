/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:01:49 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/05 14:50:37 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_len;
	size_t	res;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	res = dst_len + src_len;
	if (dst_len < dstsize)
	{
		copy_len = dstsize - dst_len - 1;
		while (index < copy_len && src[index])
			dst[dst_len++] = src[index++];
		dst[dst_len] = '\0';
	}
	return (res);
}
