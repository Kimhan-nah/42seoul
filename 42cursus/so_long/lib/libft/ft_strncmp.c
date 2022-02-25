/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:36:53 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/08 20:23:28 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && idx < n && s1[idx])
		idx++;
	if (idx == n || s1[idx] == s2[idx])
		return (0);
	else if (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx] < 0)
		return (-1);
	else
		return (1);
}
