/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:09:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/13 14:07:54 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
# include "../lib/libft/libft.h"

# include <stdio.h>

typedef struct s_args
{
	char	**envp;
	int		pipe_fd[2];

	char	*infile;
	char	*outfile;
	char	**cmds[2];

	char	**path;

}	t_args;

void	exit_msg(char *msg);
void	parsing(char *argv[], char **envp, t_args *args);
void	child_process1(t_args *args);
void	parent_process(t_args *args);
void	cmd_split(char **ret, char *str);
int		cmd_count(char *str);

#endif
