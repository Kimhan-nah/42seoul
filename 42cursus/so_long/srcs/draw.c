/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:18:15 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/28 17:02:06 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// mlx_put_image
static int	put_img(t_solong *solong, int x, int y)
{
	void	*img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(solong->mlx, "./img/asteroid-1.xpm", &width, &height);
	if (!img)
		exit_with_message("hello");

	mlx_put_image_to_window(solong->mlx, solong->win, img, x*IMG, y*IMG);		// window에 img 출력

	return (1);
}

// mlx_loop_hook에서 imgage draw 함수포인터로 사용할 함수
int	rendering(t_solong *solong)
{
	int x;
	int y;

	y = 0;
	while (y < solong->row)
	{
		x = 0;
		while (x < solong->col)
		{
			put_img(solong, x, y);
			x++;
		}
		y++;
	}

	return (1);
}
