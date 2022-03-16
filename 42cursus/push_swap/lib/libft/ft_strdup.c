/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:13:41 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 01:11:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	int		idx;
	char	*ret;

	size = ft_strlen(s1);
	idx = 0;
	ret = (char *)ft_calloc(size + 1, sizeof(char));
	if (!ret)
		return (NULL);
	while (idx < size)
	{
		ret[idx] = s1[idx];
		idx++;
	}
	return (ret);
}
