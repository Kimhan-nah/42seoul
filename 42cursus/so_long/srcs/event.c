/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:54:39 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/03 08:24:02 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_solong *solong, unsigned int x, unsigned int y)
{
	if (solong->map[x][y] == '1')
		return ;
	solong->player.x = x;
	solong->player.y = y;
	solong->step++;
	if (solong->map[x][y] == 'E')
	{
		if (solong->flag[0] == 0)
		{
			printf("===========GAME CLEAR===========\n");
			exit(EXIT_SUCCESS);
		}
		return ;
	}
	else if (solong->map[x][y] == 'C')
		solong->flag[0]--;
	solong->map[x][y] = '0';
	solong->map[solong->player.x][solong->player.y] = 'P';
}

int	key_check(int key, t_solong *solong)
{
	unsigned int	x;
	unsigned int	y;

	x = solong->player.x;
	y = solong->player.y;
	printf("Key in Win : %d\n", key);
	if (key == KEY_W)
		x--;
	else if (key == KEY_A)
		y--;
	else if (key == KEY_S)
		x++;
	else if (key == KEY_D)
		y++;
	else if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_player(solong, x, y);
	printf("Step : %u\n\n", solong->step);
	return (1);
}

int	destroy_window(t_solong	*solong)
{
	mlx_destroy_window(solong->mlx, solong->win);
	exit(EXIT_SUCCESS);
}
