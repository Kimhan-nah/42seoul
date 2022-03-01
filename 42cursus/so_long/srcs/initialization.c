/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:51:52 by hannah            #+#    #+#             */
/*   Updated: 2022/03/01 21:07:35 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_solong *solong)
{
	int width;
	int height;

	solong->img_wall = mlx_xpm_file_to_image(solong->mlx, "./img/asteroid.xpm", &width, &height);
	solong->img_bg = mlx_xpm_file_to_image(solong->mlx, "./img/bg.xpm", &width, &height);
	solong->img_player = mlx_xpm_file_to_image(solong->mlx, "./img/player.xpm", &width, &height);
	solong->img_collect = mlx_xpm_file_to_image(solong->mlx, "./img/earth_small.xpm", &width, &height);
	solong->img_exit = mlx_xpm_file_to_image(solong->mlx, "./img/blackhole.xpm", &width, &height);

	if (!solong->img_wall || !solong->img_bg || !solong->img_player || !solong->img_collect || !solong->img_exit)
		exit_with_message("Error\ninit_img error");
}

void	init_map(char *file, t_solong *solong)
{
	unsigned int i;

	i = 0;
	check_mapsize(file, solong);
	solong->map = (char **)ft_calloc(sizeof(char *), solong->row);
	if (!solong->map)
		exit_with_message("Error\nFail alloc map.");
}

void	init_solong(t_solong *solong)
{
	ft_bzero(solong, sizeof(t_solong));
	solong->mlx = mlx_init();
	if (!solong->mlx)
		exit_with_message("Error\nFail mlx_init");
	init_img(solong);
}

void	init_win(t_solong *solong)
{
	solong->win = mlx_new_window(solong->mlx, IMG*solong->col, IMG*solong->row, "mlx_test");
	if (!solong->win)
		exit_with_message("Error\nFail init_win");
}
