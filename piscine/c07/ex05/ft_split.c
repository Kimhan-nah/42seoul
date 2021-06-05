/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 02:54:28 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/19 00:53:32 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src, int end, int start)
{
	int i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int		is_sep(char ch, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	if (ch == 0)
		return (1);
	return (0);
}

void	init_split(char **ret, char *str, char *charset)
{
	int i;
	int start;
	int end;

	i = 0;
	start = 0;
	end = 0;
	while (str[end])
	{
		while (!is_sep(str[end], charset) && str[end])
			end++;
		if (end - start > 0)
		{
			if (!(ret[i] = (char *)malloc(end - start + 1)))
				return ;
			ft_strcpy(ret[i], str, end, start);
			i++;
		}
		start = end + 1;
		if (str[end])
			end++;
	}
	ret[i] = 0;
}

int		word_count(char *str, char *charset)
{
	int count;
	int end;
	int start;

	count = 0;
	end = 0;
	start = 0;
	while (str[end])
	{
		while (!is_sep(str[end], charset) && str[end])
			end++;
		if (end - start > 0)
			count++;
		start = end + 1;
		if (str[end])
			end++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		len;

	len = word_count(str, charset);
	if (!(ret = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	init_split(ret, str, charset);
	return (ret);
}
