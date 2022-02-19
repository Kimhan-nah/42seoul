/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:17:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/06/03 15:17:27 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		idx;
	char	*ret;

	size = ft_strlen(s1);
	idx = 0;
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	while (idx < size)
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (!ptr)
		return (NULL);
	while (*ptr && *ptr != c)
		ptr++;
	if (*ptr == c)
		return (ptr);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ret;
	const unsigned char	*s;
	size_t				idx;

	if (!dst && !src)
		return (0);
	ret = (unsigned char *)dst;
	s = (const unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		ret[idx] = s[idx];
		idx++;
	}
	return (ret);
}
