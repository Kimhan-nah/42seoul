/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:46 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 18:30:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	parent_process(char *argv[], char **envp)
{
}

void	child_process()
{
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid;
	t_args *args;

	args = (t_args *)ft_calloc(1, sizeof(t_args));

	if (argc != 5 || !envp)
		exit(EXIT_FAILURE);

	if (pipe(fd) == -1)			// pipe 생성
		exit(EXIT_FAILURE);

	parsing(argv, envp, args);
	pid = fork();				// 자식 프로세스 생성	
	if (pid == 0)				// 자식 프로세스일 경우
		child_process();
	else if (pid > 0)			// 부모 프로세스일 경우
		parent_process(argv, envp);
	else						// error
	{
		printf("fork pid error\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}

