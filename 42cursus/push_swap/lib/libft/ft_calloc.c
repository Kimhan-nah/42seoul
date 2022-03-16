/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:32:35 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 00:03:33 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			idx;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (0);
	idx = 0;
	while (idx < count * size)
	{
		mem[idx] = 0;
		idx++;
	}
	return (mem);
}
