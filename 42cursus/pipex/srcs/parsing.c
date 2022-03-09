/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:19:49 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 15:13:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*strcut(char *start, char *end)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
//	if (*start == '\'' || *start == '\"')
//		start++;
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

static char	**cmd_parsing(char *argv)
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

static void	envp_parsing(char **envp, t_args *args)
{
	int i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH", ft_strlen(envp[i]));
		if (path)
		{
			args->envp = ft_split(path + 5, ':');
			return ;
		}
		i++;
	}
}

void	parsing(char *argv[], char **envp, t_args *args)
{
	args->infile = argv[1];
	args->outfile = argv[4];
	envp_parsing(envp, args);
	args->cmds[0] = cmd_parsing(argv[2]);
	args->cmds[1] = cmd_parsing(argv[3]);
}

