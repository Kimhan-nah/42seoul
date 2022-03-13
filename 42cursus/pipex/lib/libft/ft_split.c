/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:54:55 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/13 11:54:07 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/pipex.h"

static char	*my_strcpy(char *dest, char const *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '/';
	return (dest);
}

static int	init_split(char **ret, char const *s, char c)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] != c && s[end])
			end++;
		if (end - start > 0)
		{
			ret[i] = (char *)ft_calloc(end - start + 2, sizeof(char));
			my_strcpy(ret[i], s, start, end);
			i++;
		}
		start = end + 1;
		if (s[end])
			end++;
	}
	return (0);
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	end;
	int	start;

	count = 0;
	end = 0;
	start = 0;
	while (s[end])
	{
		while (s[end] != c && s[end])
			end++;
		if (end - start > 0)
			count++;
		start = end + 1;
		if (s[end])
			end++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		len;

	if (s == 0)
		return (0);
	len = word_count(s, c);
	ret = (char **)ft_calloc(len + 1, sizeof(char *));
	init_split(ret, s, c);
	return (ret);
}
