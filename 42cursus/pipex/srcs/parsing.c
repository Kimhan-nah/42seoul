/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:19:49 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/13 13:58:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**cmd_parsing(char *argv)
{
	char	*str;
	char	**ret;
	int		len;
	int		i;

	str = ft_strtrim(argv, " ");
	len = cmd_count(str);
	i = 0;
	ret = (char **)ft_calloc(len + 1, sizeof(char *));
	cmd_split(ret, str);
	free(str);
	return (ret);
}

static void	path_parsing(t_args *args)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (args->envp[i])
	{
		path = ft_strnstr(args->envp[i], "PATH", ft_strlen(args->envp[i]));
		if (path)
		{
			args->path = ft_split(path + 5, ':');
			return ;
		}
		i++;
	}
}

void	parsing(char *argv[], char **envp, t_args *args)
{
	args->envp = envp;
	args->pipe_fd[READ] = 0;
	args->pipe_fd[WRITE] = 0;
	args->infile = argv[1];
	args->outfile = argv[4];
	args->cmds[0] = cmd_parsing(argv[2]);
	args->cmds[1] = cmd_parsing(argv[3]);
	path_parsing(args);
}
