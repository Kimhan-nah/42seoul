/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:54:39 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/01 21:36:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(int key, t_solong *solong)
{
	unsigned int	x;
	unsigned int	y;

	x = solong->player.x;
	y = solong->player.y;

	if (key == KEY_W)		// up
		x--;
	else if (key == KEY_A)	// left
		y--;
	else if (key == KEY_S)	// down
		x++;
	else if (key == KEY_D)	// right
		y++;

	if (solong->map[x][y] == '1')
		return ;
	solong->player.x = x;
	solong->player.y = y;
	solong->step++;
	if (solong->map[x][y] == 'E')		// 처리@@@@@@@@@
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
	printf("Key in Win : %d\n", key);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);

	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_player(key, solong);
	printf("Step : %u\n\n", solong->step);
	return (1);
}

int	destroy_window(t_solong	*solong)
{
	mlx_destroy_window(solong->mlx, solong->win);
	exit(EXIT_SUCCESS);
}

//int	destroy_window(int button, int x, int y, t_solong	*solong)
//{
//	printf("%d %d\n", x, y);
//	if (x == 0 && y == 0)
//	{
//		printf("%d\n", button);
//		mlx_destroy_window(solong->mlx, solong->win);
//		exit(EXIT_SUCCESS);
//	}
//	return 1;
//}
