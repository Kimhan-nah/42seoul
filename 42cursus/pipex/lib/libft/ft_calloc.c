/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:32:35 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 14:09:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			idx;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		exit_msg("libft : ft_calloc");
	idx = 0;
	while (idx < count * size)
	{
		mem[idx] = 0;
		idx++;
	}
	return (mem);
}
