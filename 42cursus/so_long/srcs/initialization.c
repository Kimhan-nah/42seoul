/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:51:52 by hannah            #+#    #+#             */
/*   Updated: 2022/04/24 18:22:04 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_mapsize(char *file, t_solong *solong)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_message("Error\nInvalid file.");
	while (get_next_line(fd, &line) > 0)
	{
		solong->row++;
		if (solong->row == 1)
			solong->col = ft_strlen(line);
		else if (ft_strlen(line) != solong->col)
			exit_with_message("Error\nInvalid map size. It is not square 1");
		free(line);
	}
	close(fd);
	if (*line)
	{
		solong->row++;
		if (ft_strlen(line) != solong->col)
			exit_with_message("Error\nInvalid map size. It is not square 2.");
	}
	if (solong->row < 3 || solong->col < 3 || solong->row * solong->col < 15)
		exit_with_message("Error\nInvalid map size.");
	free(line);
}

static void	init_img(t_solong *solong)
{
	int	width;
	int	height;

	solong->img_wall = mlx_xpm_file_to_image(solong->mlx, \
			"./img/asteroid.xpm", &width, &height);
	solong->img_bg = mlx_xpm_file_to_image(solong->mlx, \
			"./img/bg.xpm", &width, &height);
	solong->img_player = mlx_xpm_file_to_image(solong->mlx, \
			"./img/player.xpm", &width, &height);
	solong->img_collect = mlx_xpm_file_to_image(solong->mlx, \
			"./img/earth_small.xpm", &width, &height);
	solong->img_exit = mlx_xpm_file_to_image(solong->mlx, \
			"./img/blackhole.xpm", &width, &height);
	if (!solong->img_wall || !solong->img_bg \
			|| !solong->img_player || !solong->img_collect || !solong->img_exit)
		exit_with_message("Error\ninit_img error");
}

static void	init_map(char *file, t_solong *solong)
{
//	unsigned int	i;
//
//	i = 0;
	check_mapsize(file, solong);
	solong->map = (char **)ft_calloc(sizeof(char *), solong->row);
	if (!solong->map)
		exit_with_message("Error\nFail alloc map.");
}

void	init_solong(char *file, t_solong *solong)
{
	ft_bzero(solong, sizeof(t_solong));
	init_map(file, solong);
	solong->mlx = mlx_init();
	if (!solong->mlx)
		exit_with_message("Error\nFail mlx_init");
	solong->win = mlx_new_window(solong->mlx, \
			IMG * solong->col, IMG * solong->row, "mlx_test");
	if (!solong->win)
		exit_with_message("Error\nFail mlx_new_window");
	init_img(solong);
}
