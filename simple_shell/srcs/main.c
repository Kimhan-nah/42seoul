#include "../includes/pipex.h"

//static void	cmd_execve(char **cmd, int cmd_index)
static void	cmd_execve(char **cmd)
{
//	printf("cmd : %s\n", *cmd);
	execvp(cmd[0], cmd);
//	execvp("lsd", cmd);
	exit_msg(strerror(errno));
}

void	first_child_process(t_info *info)
{
	int		infile_fd;

	if (info->infile == NULL)
		infile_fd = 0;				// STDIN
	else
		infile_fd = open(info->infile, O_RDONLY);

	if (infile_fd < 0)
		exit_msg(strerror(errno));

	if (info->cmds[1] == NULL)
	{
		if (dup2(infile_fd, STDIN_FILENO) == -1)				// STDIN -> infile_fd
			exit_msg(strerror(errno));
	}
	else
	{
		if (dup2(infile_fd, STDIN_FILENO) == -1				// STDIN -> infile_fd
			|| dup2(info->pipe_fd[WRITE], STDOUT_FILENO) == -1)		// STDOUT -> pipe_fd[WRITE]
			exit_msg(strerror(errno));
	}

	close(info->pipe_fd[WRITE]);
	close(info->pipe_fd[READ]);
	if (infile_fd != 0)
		close(infile_fd);

//	cmd_execve(info->cmds[0], 0);
	cmd_execve(info->cmds[0]);
}

static void	second_child_process(t_info *info)
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

void	parent_process(t_info *info)
{
	pid_t	pid;
	int		statloc;

	pid = 1;
	if (info->cmds[1] != NULL)		// 1개
		pid = fork();
	if (pid == -1)
		exit_msg(strerror(errno));
	else if (pid == 0)
		second_child_process(info);
	else
	{
		close(info->pipe_fd[READ]);
		close(info->pipe_fd[WRITE]);
		while (wait(&statloc) != -1)
			;
	}
}

int	main(void)
{
	int		should_run = 1;
	char	str[MAX_LINE];
	t_info	*info;
	pid_t	pid;

	while (should_run)
	{
		printf("osh>");
		fgets(str, sizeof(str), stdin);		// enter
		fflush(stdout);

		info = (t_info *)calloc(1, sizeof(t_info));
		parsing(info, str);

//		printf("cmd : %s\n", info->cmds[0][0]);
//		printf("cmd : %p\n", info->cmds[1]);
//		printf("==");

		if (pipe(info->pipe_fd) == -1)		// create pipe
			exit_msg(strerror(errno));

		pid = fork();						// fork
		if (pid == -1)
			exit_msg(strerror(errno));
		else if (pid == 0)
			first_child_process(info);
		else
			parent_process(info);

		free(info);
	}

	return (0);
}
