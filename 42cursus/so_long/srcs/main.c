/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/19 16:55:49 by hannkim          ###   ########.fr       */
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

void	isValidFile(int argc, char *argv[])
{
	char	*ptr;
	char	*extension;
	int		i;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid Argument.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ptr = argv[1];
	extension = ".ber";
	i = 0;
	while (*ptr)
		ptr++;
	ptr -= 4;
	while (*ptr)
	{
		if (ptr[i] != extension[i])
		{
			ft_putendl_fd("Invalid file extension.", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	parsing(char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Invalid file.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > -1)
	{
	}
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

