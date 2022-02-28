/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:30:04 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/28 18:36:13 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG 100
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"

# include <stdio.h>

typedef struct s_solong
{
	void	*mlx;
	void	*win;

	char	**map;
	int	row;
	int	col;
	int flag[3];
} t_solong;


extern void	check_arg(int argc, char *argv[]);
extern void	check_mapsize(char *file, t_solong *solong);
extern void	parsing(char *file, t_solong *solong);
extern void	exit_with_message(char *message);
extern void	init_solong(t_solong *solong);
extern void	init_map(char *file, t_solong *solong);
extern void	init_win(t_solong *solong);
extern int	rendering(t_solong *solong);

#endif
