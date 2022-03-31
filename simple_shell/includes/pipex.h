#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1
# define MAX_LINE 80

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>


typedef struct s_info
{
	int		pipe_fd[2];
	char	*infile;
	char	*outfile;
	char	**cmds[2];

	int		background;
}	t_info;

void	parsing(t_info *info, char *str);
void	parent_processor(t_info *info);
void	first_child_processor(t_info *info);
void	exit_msg(char *msg);
char	*strtrim(char const *s1, char const *set);
//char	*ft_strtrim(char const *s1, char const *set);
//void	putendl_fd(char *s, int fd);
//char	*ft_strjoin(char const *s1, char const *s2);
//void	cmd_split(char **ret, char *str);
//int		cmd_count(char *str);

#endif
