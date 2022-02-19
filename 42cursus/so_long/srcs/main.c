/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/19 17:02:18 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_check(int key, void *p)
{
	printf("Key in Win : %d\n", key);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	// check file extension and argc
	isValidFile(argc, argv);

	//parsing and vailidating
	parsing(argv[1]);

	mlx = mlx_init();
	if (!mlx)
		return (EXIT_FAILURE);
	win = mlx_new_window(mlx, 500, 500, "mlx_test");
	if (!win)
		return (EXIT_FAILURE);
	//init mlx and mlx_image
	//draw 

	//hook
	mlx_key_hook(win, key_check, win);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

