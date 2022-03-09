/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:32:02 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 18:33:14 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*strcut(char *start, char *end)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	if (*end == '\'' || *end == '\"')
		end--;
	len = end - start + 1;
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	while (i < len)
	{
		ret[i] = *start;
		i++;
		start++;
	}
	return (ret);
}

static void	init_split(char **ret, char *str)
{
	char	*start;
	char	*end;
	char	chr;
	int		i;

	start = str;
	end = str;
	i = 0;
	while (*end)
	{
		if (*start != '\'' && *start != '\"')
			chr = ' ';
		else
		{
			chr = *start;
			end++;
			start++;
		}
		while (*end != chr && *end)
			end++;
		if (end - start > 0)
		{
			ret[i] = strcut(start, end);
			i++;
		}
		while (*end == ' ')
			end++;
		start = end;
	}
}

static int	word_count(char *str)
{
	char	*start;
	char	*end;
	char	chr;
	int		count;

	start = (char *)str;
	end = (char	*)str; //ab 'c'
	count = 0;
	while (*end)
	{
		if (*start != '\'' && *start != '\"')
			chr = ' ';
		else
		{
			chr = *start;
			end++;
			start++;
		}
		while (*end != chr && *end)
			end++;
		if (end - start > 0)
			count++;
		while (*end == ' ' &&  *end)
			end++;
		start = end;
	}
	return (count);
}

char	**cmd_parsing(char *argv)
{
	char	*str;
	char	**ret;
	int		wc;
	int		i;

	str = ft_strtrim(argv, " ");
	wc = word_count(str);
	i = 0;
	ret = (char	**)ft_calloc(wc + 2, sizeof(char *));
	init_split(ret, str);
	free(str);
	return (ret);
}
