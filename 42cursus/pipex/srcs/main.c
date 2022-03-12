/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:46 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/12 21:29:03 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	exit_msg(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	t_args *args;

	if (argc != 5)
		exit_msg("argc error");
	args = (t_args *)ft_calloc(1, sizeof(t_args));
	parsing(argv, envp, args);
	if (pipe(args->pipe_fd) == -1)			// pipe 생성
		exit(EXIT_FAILURE);
	pid = fork();				// 자식 프로세스 생성	
	if (pid == -1)				// 자식 프로세스일 경우
		exit_msg("fork pid error");
	else if (pid == 0)
		child_process1(args);
	else			// 부모 프로세스일 경우
		parent_process(args);

	return (0);
}
