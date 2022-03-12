/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:36:19 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/12 22:28:23 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_file(t_args *args)
{
	char	*filename;
	char	*tmp;
	int		i;
	int a;

	i = 0;
	filename = ft_strjoin(args->path[i], "/");
	filename = ft_strjoin(filename, args->cmds[0][0]);
	while ((a = access(filename, X_OK)) != 0)		// 0이면중단 실행권한
	{
//		printf("access : %d\n", a);
//		printf("filename : %s\n", filename);
		i++;
		if (!args->path[i])		// 끝까지 못찾았을 경우 => 어떻게 처리?
			return (NULL);
		tmp = filename;
		filename = ft_strjoin(args->path[i], "/");
		filename = ft_strjoin(filename, args->cmds[0][0]);
		free(tmp);
	}
	return (filename);
}

static void	cmd_execve(t_args *args)
{
	char	*filename;

	filename = find_file(args);
	if (!filename) 
		exit_msg("command not found");
	if (execve(filename, args->cmds[0], args->envp) == -1)
		exit_msg(strerror(errno));
}

void	child_process1(t_args *args)
{
	int		infile_fd;

	infile_fd = open(args->infile, O_RDONLY);
	if (infile_fd < 0)
		exit_msg("fd error");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		exit_msg("redirection error");
	close(args->pipe_fd[READ]);
	close(infile_fd);
	cmd_execve(args);		// 프로세스 대체 돼서 마지막에 있어야 됨
}

static void	child_process2(t_args *args)
{
	int		outfile_fd;

	outfile_fd = open(args->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);		// 권한 테스트
	if (outfile_fd < 0)
		exit_msg("fd error");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		exit_msg("redirection error");
	close(args->pipe_fd[WRITE]);
	close(outfile_fd);
	cmd_execve(args);
}

void	parent_process(t_args *args)
{
	pid_t	pid;
	int		statloc;

	pid = fork();
	if (pid == -1)
		exit_msg("fork pid error");
	else if (pid == 0)
		child_process2(args);
	else			// 부모 프로세스일 경우
	{
		// wait로 자식 프로세스 종료 기다리기   => 2개의 자식 프로세스 모두 기다려야 함??
		while (!waitpid(-1, &statloc, WNOHANG));

		// 마지막 종료된 자식 프로세스의 exit 상태 확인 가능!
//		printf("%d\n", WEXITSTATUS(statloc));
		close(args->pipe_fd[READ]);
		close(args->pipe_fd[WRITE]);
	}
}

