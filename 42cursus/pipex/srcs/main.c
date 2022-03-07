/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:46 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 13:07:46 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parsing(int argc, char *argv[], char **envp, t_args *args)
{
	args->argc = argc;
	args->envp = envp;
	args->infile = argv[1];
	args->outfile = argv[4];

	args->cmds[0] = ft_split(argv[2], ' ');
	args->cmds[1] = ft_split(argv[3], ' ');
	if (!args->cmds[0] || !args->cmds[1])
		exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	t_args	*args;

	if (argc != 5)
		exit(EXIT_FAILURE);
	args = (t_args	*)ft_calloc(1, sizeof(t_args));
	parsing(argc, argv, envp, args);

	printf("%s\n", args->cmds[0][0]);

	return (0);
}
