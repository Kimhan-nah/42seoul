/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:46 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/10 19:41:36 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * dup2, execve, exit_msg(strerror()) 노션 확인
 *
 */

#include "../includes/pipex.h"

void	exit_msg(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	child_process1(t_args *args)
{
	char	*filename;
	char	*tmp;
	int		i;

	i = 0;

//	if (dup2(blah, blah) == -1)
//	{
//		exit_msg(strerror(errno));
//	}
//	dup2(pipe, STDIN_FILENO);

	filename = ft_strjoin(args->path[i], args->cmds[0][0]);
	// 끝까지 못찾았을 경우 추가하기
	while (access(filename, X_OK) != 0)
	{
		i++;
		tmp = filename;
		filename = ft_strjoin(args->path[i], args->cmds[0][0]);
		free(tmp);
	}
	execve(filename, args->cmds[0], args->envp);
}

void	child_process2(t_args *args)
{
	char	*filename;
	char	*tmp;
	int		i;

	i = 0;
	filename = ft_strjoin(args->path[i], args->cmds[1][0]);
	while (access(filename, X_OK) != 0)
	{
		i++;
		tmp = filename;
		filename = ft_strjoin(args->path[i], args->cmds[1][0]);
		free(tmp);
	}
	execve(filename, args->cmds[1], args->envp);

}

void	parent_process(t_args *args)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_msg("fork pid error");
	else if (pid == 0)
		child_process2(args);
	else			// 부모 프로세스일 경우
	{
		// dup2로 파이프 닫기
		// wait로 자식 프로세스 종료 기다리기
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid;
	t_args *args;

	args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (pipe(fd) == -1)			// pipe 생성
		exit(EXIT_FAILURE);
	parsing(argv, envp, args);
	pid = fork();				// 자식 프로세스 생성	
	if (pid == -1)				// 자식 프로세스일 경우
		exit_msg("fork pid error");
	else if (pid == 0)
		child_process1(args);
	else			// 부모 프로세스일 경우
		parent_process(args);

	return (0);
}
