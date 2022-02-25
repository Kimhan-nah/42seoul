/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:30:04 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/25 15:31:54 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <mlx.h>
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

	void	*wall;
	void	*player;
	void	*exit;
	void	*bg;
	void	*collect;

	t_list	*map;
	int	row;
	int	col;
} t_solong;

typedef struct s_img
{
	char	*path;
	int	*texture;
	int	width;
	int	height;
}	t_img;


extern void	check_file(int argc, char *argv[]);
extern void	parsing(char *file, t_solong *solong);
extern void	exit_with_message(char *message);
extern int	draw_map(t_list map);

#endif
