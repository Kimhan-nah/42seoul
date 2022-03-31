#include "../includes/pipex.h"

static void	cmd_execve(char **cmd)
{
	execvp(cmd[0], cmd);
	exit_msg(strerror(errno));
}

void	first_child_processor(t_info *info)
{
	int		infile_fd;
	int		outfile_fd;

	if (info->infile == NULL)
		infile_fd = STDIN_FILENO;				// STDIN
	else
		infile_fd = open(info->infile + 2, O_RDONLY);		// infile

	if (info->outfile == NULL)
		outfile_fd = STDOUT_FILENO;				// STDOUT
	else
	{
		outfile_fd = open(info->outfile + 2, O_WRONLY | O_TRUNC | O_CREAT, 0644);		// outfile
	}

	if (infile_fd < 0 || outfile_fd < 0)
	{
		exit_msg(strerror(errno));
	}

	if (info->cmds[1] == NULL)	// cmd 1개일 경우
	{
		if (infile_fd != STDIN_FILENO && dup2(infile_fd, STDIN_FILENO) == -1)	// STDIN -> infile_fd
			exit_msg(strerror(errno));
		if (outfile_fd != STDOUT_FILENO && dup2(outfile_fd, STDOUT_FILENO) == -1)	// STDOUT -> outfile_fd
			exit_msg(strerror(errno));
	}
	else						// cmd가 2개일 경우
	{
		if (dup2(infile_fd, STDIN_FILENO) == -1			// STDIN -> infile_fd
			|| dup2(info->pipe_fd[WRITE], STDOUT_FILENO) == -1)		// STDOUT -> pipe_fd[WRITE]
			exit_msg(strerror(errno));
		close(info->pipe_fd[WRITE]);
		close(info->pipe_fd[READ]);
	}

	if (infile_fd != STDIN_FILENO)
		close(infile_fd);
	if (outfile_fd != STDOUT_FILENO)
		close(outfile_fd);

	cmd_execve(info->cmds[0]);
}

static void	second_child_processor(t_info *info)
{
	int		outfile_fd;

	if (info->outfile == NULL)
		outfile_fd = 1;					// STDOUT
	else
		outfile_fd = open(info->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if (outfile_fd < 0)				// open error
		exit_msg(strerror(errno));

	if (dup2(outfile_fd, STDOUT_FILENO) == -1			// STDOUT -> outfile_fd
		|| dup2(info->pipe_fd[READ], STDIN_FILENO) == -1)	// STDIN -> pipe_fd[READ]
		exit_msg(strerror(errno));

	close(info->pipe_fd[READ]);
	close(info->pipe_fd[WRITE]);
	if (outfile_fd != 1)
		close(outfile_fd);

	cmd_execve(info->cmds[1]);
//	cmd_execve(info->cmds[1], 1);
//	cmd_execve(info, 1);
}

void	parent_processor(t_info *info)
{
	pid_t	pid;
	int		statloc;

	pid = 1;
	if (info->cmds[1] != NULL)		// 명령어 2개일 경우 한번 더 fork
		pid = fork();
	if (pid == -1)
		exit_msg(strerror(errno));
	else if (pid == 0)
		second_child_processor(info);
	else
	{
		close(info->pipe_fd[READ]);
		close(info->pipe_fd[WRITE]);
		
		if (info->background == 0)		// no background -> wait
			while (wait(&statloc) != -1) ;
	}
}

