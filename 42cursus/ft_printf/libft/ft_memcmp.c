/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:11:20 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/11 13:33:09 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			idx;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n && str1[idx] == str2[idx])
		idx++;
	if (idx == n)
		return (0);
	return (str1[idx] - str2[idx]);
}
