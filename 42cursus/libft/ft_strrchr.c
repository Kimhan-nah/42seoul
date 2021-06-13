/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:09:30 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/20 22:13:28 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t idx;

	idx = ft_strlen(s);
	c %= 256;
	while (idx && s[idx] != c)
		idx--;
	if (s[idx] == c)
		return ((char *)(s + idx));
	return (NULL);
}
