/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/03 08:26:05 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;

	check_arg(argc, argv);
	init_solong(argv[1], &solong);
	parsing(argv[1], &solong);
	mlx_hook(solong.win, 2, 0, key_check, &solong);
	mlx_hook(solong.win, 17, 0, destroy_window, &solong);
	mlx_loop_hook(solong.mlx, rendering, &solong);
	mlx_loop(solong.mlx);
	return (EXIT_SUCCESS);
}
