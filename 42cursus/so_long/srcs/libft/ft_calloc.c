/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:32:35 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/22 15:15:01 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			idx;

	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		exit_with_error_message("Error\nFail Alloc");
	idx = 0;
	while (idx < count * size)
	{
		mem[idx] = 0;
		idx++;
	}
	return (mem);
}
