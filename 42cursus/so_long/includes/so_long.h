/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:30:04 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/03 08:39:19 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG 64
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define UP 13
# define LEFT 0
# define DOW1
# define RIGHT 2

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"

# include <stdio.h>

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	cnt;

}	t_player;

typedef struct s_solong
{
	void			*mlx;
	void			*win;

	char			**map;
	unsigned int	col;
	unsigned int	row;
	int				flag[3];

	t_player		player;
	unsigned int	step;

	void			*img_wall;
	void			*img_bg;
	void			*img_player;
	void			*img_collect;
	void			*img_exit;
}	t_solong;

void	init_solong(char *file, t_solong *solong);
void	parsing(char *file, t_solong *solong);
int		key_check(int key, t_solong *solong);
void	check_arg(int argc, char *argv[]);
int		rendering(t_solong *solong);
int		destroy_window(t_solong	*solong);
void	exit_with_message(char *message);

#endif
