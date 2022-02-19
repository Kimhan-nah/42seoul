/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:58:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 00:50:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		res = (char *)(haystack + i);
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && *(haystack + i + j)
				&& i + j < len)
			j++;
		if (*(needle + j) == 0)
			return (res);
		i++;
	}
	return (NULL);
}
