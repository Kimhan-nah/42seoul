/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:36:58 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/17 17:18:23 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	index;

	src_len = ft_strlen(src);
	index = 0;
	if (dstsize == 0)
		return (src_len);
	while (index < src_len && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (src_len);
}
