/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:09:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 19:59:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

# include <stdio.h>

typedef struct s_args
{
	char	**envp;

	char	*infile;
	char	*outfile;
	char	**cmds[2];		// cmds[2][*][*]

	char	**path;

}	t_args;

void	exit_msg(char *msg);
void	parsing(char *argv[], char **envp, t_args *args);
char	**cmd_parsing(char *argv);

#endif
