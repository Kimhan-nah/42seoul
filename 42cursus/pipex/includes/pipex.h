/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:09:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 18:20:42 by hannkim          ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
	char	**cmds[2];		// cmds[2][*][*]
	char	**envp;

}	t_args;

void	exit_msg(char *msg);
void	parsing(char *argv[], char **envp, t_args *args);

#endif
