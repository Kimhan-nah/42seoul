/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 00:23:45 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 01:13:49 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int idx;

	idx = 0;
	while (set[idx] && set[idx] != c)
		idx++;
	if (set[idx] == c)
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		idx;
	int		start;
	int		end;

	idx = 0;
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && start < end)
		end--;
	strtrim = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (!strtrim)
		return (NULL);
	while (start <= end)
		strtrim[idx++] = s1[start++];
	return (strtrim);
}
