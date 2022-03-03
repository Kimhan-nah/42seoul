/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:18:15 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/03 08:53:38 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_img(t_solong *solong, void *img, unsigned int x, unsigned int y)
{
	if (img)
		mlx_put_image_to_window(solong->mlx, solong->win, img, \
				x * IMG, y * IMG);
	if (solong->player.x == y && solong->player.y == x)
		mlx_put_image_to_window(solong->mlx, solong->win, solong->img_player, \
				x * IMG, y * IMG);
}

int	rendering(t_solong *solong)
{
	unsigned int	x;
	unsigned int	y;
	void			*img;

	y = 0;
	while (y < solong->row)
	{
		x = 0;
		while (x < solong->col)
		{
			img = 0;
			mlx_put_image_to_window(solong->mlx, solong->win, \
					solong->img_bg, x * IMG, y * IMG);
			if (solong->map[y][x] == '1')
				img = solong->img_wall;
			else if (solong->map[y][x] == 'E')
				img = solong->img_exit;
			else if (solong->map[y][x] == 'C')
				img = solong->img_collect;
			put_img(solong, img, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
