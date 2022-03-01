/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:18:15 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/01 21:39:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// mlx_loop_hook에서 imgage draw 함수포인터로 사용할 함수
int	rendering(t_solong *solong)
{
	unsigned int x;
	unsigned int y;

	y = 0;
	while (y < solong->row)
	{
		x = 0;
		while (x < solong->col)
		{
			mlx_put_image_to_window(solong->mlx, solong->win, solong->img_bg, x * IMG, y * IMG);
			if (solong->map[y][x] == '1')		// wall
				mlx_put_image_to_window(solong->mlx, solong->win, solong->img_wall, x * IMG, y * IMG);
			else if (solong->map[y][x] == 'E')
				mlx_put_image_to_window(solong->mlx, solong->win, solong->img_exit, x * IMG, y * IMG);
			else if (solong->map[y][x] == 'C')
				mlx_put_image_to_window(solong->mlx, solong->win, solong->img_collect, x * IMG, y * IMG);

			mlx_put_image_to_window(solong->mlx, solong->win, solong->img_player, solong->player.y * IMG, solong->player.x * IMG);

			x++;
		}
		y++;
	}

	return (1);
}
