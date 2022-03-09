/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 00:23:45 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 11:48:26 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/pipex.h"

static int	is_set(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx] && set[idx] != c)
		idx++;
	if (set[idx] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		idx;
	int		start;
	int		end;

	idx = 0;
	start = 0;
	if (!s1)
		exit_msg("ft_strtrim");
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && start < end)
		end--;
	strtrim = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (!strtrim)
		exit_msg("ft_strtrim");
	while (start <= end)
		strtrim[idx++] = s1[start++];
	return (strtrim);
}
