/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:42:09 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 18:00:37 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*strsub;
	unsigned int	idx;

	if (!s)
		exit_msg("ft_substr");
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	strsub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!strsub)
		exit_msg("ft_substr");
	idx = 0;
	while (idx < len && s[start])
	{
		strsub[idx] = s[start];
		idx++;
		start++;
	}
	return (strsub);
}
