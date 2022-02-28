/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/28 18:30:22 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_check(int key)
{
	printf("Key in Win : %d\n", key);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int main(int argc, char **argv)
{
	t_solong	solong;

	check_arg(argc, argv);
	init_solong(&solong);
	init_map(argv[1], &solong);
	parsing(argv[1], &solong);
	init_win(&solong);
	
	mlx_key_hook(solong.win, key_check, solong.win);
	mlx_loop_hook(solong.mlx, rendering, &solong);
	mlx_loop(solong.mlx);

	return (EXIT_SUCCESS);
}

