/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:22:58 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/06 14:04:58 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;
	size_t			idx;

	ret = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		ret[idx] = c;
		idx++;
	}
	return (ret);
}
