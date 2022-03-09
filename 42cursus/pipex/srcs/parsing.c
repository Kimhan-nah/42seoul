/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:19:49 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 19:05:17 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	envp_parsing(t_args *args)
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
	args->argv = argv;

	args->infile = argv[1];
	args->outfile = argv[4];
	args->cmds[0] = cmd_parsing(argv[2]);
	args->cmds[1] = cmd_parsing(argv[3]);
	
	envp_parsing(args);
}

