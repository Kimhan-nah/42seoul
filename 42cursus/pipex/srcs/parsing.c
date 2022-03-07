/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:19:49 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 18:28:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	cmd_parsing(char *argv[], t_args *args)
{
	args->cmds[0] = ft_split(argv[2], ' ');
	args->cmds[1] = ft_split(argv[3], ' ');		// fd2[1] -> pipe -> fd1[0]
	if (!args->cmds[0] || !args->cmds[1])
		exit(EXIT_FAILURE);
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
	cmd_parsing(argv, args);
}

