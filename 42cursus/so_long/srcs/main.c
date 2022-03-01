/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/01 21:43:32 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int main(int argc, char **argv)
{
	t_solong	solong;

	check_arg(argc, argv);
	init_solong(&solong);
	init_map(argv[1], &solong);
	parsing(argv[1], &solong);
	init_win(&solong);
	
	mlx_hook(solong.win, 2, 0, key_check, &solong);		// 2 : mlx_key_hook, key_hook(int keycode, void *param)
	mlx_hook(solong.win, 17, 0, destroy_window, &solong);		// 17 : mlx_mouse_hook
	mlx_loop_hook(solong.mlx, rendering, &solong);
	mlx_loop(solong.mlx);


	return (EXIT_SUCCESS);
}

