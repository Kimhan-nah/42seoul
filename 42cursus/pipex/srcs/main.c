/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:46 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/13 14:05:52 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	t_args	*args;

	if (argc != 5)
		exit_msg("argc error");
	args = (t_args *)ft_calloc(1, sizeof(t_args));
	parsing(argv, envp, args);
	if (pipe(args->pipe_fd) == -1)
		exit_msg(strerror(errno));
	pid = fork();
	if (pid == -1)
		exit_msg(strerror(errno));
	else if (pid == 0)
		child_process1(args);
	else
		parent_process(args);
	return (0);
}
