#include "../includes/pipex.h"

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
		if (strchr(str, '&') != NULL)		// background
			info->background = 1;

		parsing(info, str);

		if (strcmp(info->cmds[0][0], "exit") == 0)
			exit_msg("exit");

		if (pipe(info->pipe_fd) == -1)		// create pipe
			exit_msg(strerror(errno));

		pid = fork();						// fork
		if (pid == -1)
			exit_msg(strerror(errno));
		else if (pid == 0)
			first_child_processor(info);
		else
			parent_processor(info);

		free(info);
	}

	return (0);
}
