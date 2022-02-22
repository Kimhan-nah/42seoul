/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:55:38 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/08 19:41:55 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			idx;

	ret = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (ret[idx] == (unsigned char)c)
			return (ret + idx);
		idx++;
	}
	return (0);
}
