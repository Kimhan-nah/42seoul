/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:51:52 by hannah            #+#    #+#             */
/*   Updated: 2022/02/28 18:32:18 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(char *file, t_solong *solong)
{
	int i;

	i = 0;
	check_mapsize(file, solong);
	solong->map = (char **)ft_calloc(sizeof(char *), solong->row);
	if (!solong->map)
		exit_with_message("Error\nFail alloc map.");
	while (i < solong->row)
	{
		(solong->map)[i] = (char *)ft_calloc(sizeof(char), solong->col);
		if (!(solong->map)[i])
			exit_with_message("Error\nFail alloc map.");
		i++;
	}
}

void	init_solong(t_solong *solong)
{
	solong = (t_solong *)ft_calloc(sizeof(t_solong), 1);
	if (!solong)
		exit_with_message("Error\nFail alloc");
	solong->mlx = mlx_init();
	if (!solong->mlx)
		exit_with_message("Error\nFail mlx_init");
}

void	init_win(t_solong *solong)
{
	solong->win = mlx_new_window(solong->mlx, IMG*solong->col, IMG*solong->row, "mlx_test");
	if (!solong->win)
		exit_with_message("Error\nFail init_win");
}
