/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/25 16:31:24 by hannkim          ###   ########.fr       */
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

void	init_solong(t_solong *solong)
{
//	int width;
//	int	height;

	solong->mlx = mlx_init();

	
	solong->win = mlx_new_window(solong->mlx, 500, 500, "mlx_test");
	solong->map = (t_list *)ft_calloc(sizeof(t_list), 1);

	//solong->wall = mlx_xpm_file_to_image(solong->mlx, "../img/asteroid-1.xpm", &width, &height);		// img 포인터로 저장


	if (!solong->mlx || !solong->win || !solong->map)
		exit_with_message("Error\nFail init_solong");
	solong->row = 0;
	solong->col = 0;
}

int main(int argc, char **argv)
{
	t_solong	*solong;
	void	*img1;
	int	width;
	int	height;
	

	// check file extension and argc
	solong = (t_solong *)ft_calloc(sizeof(t_solong), 1);
	if (!solong)
		exit_with_message("Error\nFail alloc");
	init_solong(solong);
	check_file(argc, argv);
	

	//parsing and vailidating
	parsing(argv[1], solong);


//	if (open("./img/asteroid-1.xpm", O_RDONLY) == -1)
//		exit_with_message("open error");
		
	img1 = mlx_xpm_file_to_image(solong->mlx, "./img/asteroid-1.xpm", &width, &height);
	if (!img1)
		exit_with_message("hello");


	mlx_put_image_to_window(solong->mlx, solong->win, img1, 50, 50);		// window에 img 출력
	//mlx_put_image_to_window(solong->mlx, solong->win, solong->wall, 50, 50);		// window에 img 출력
//	mlx_put_image_to_window(solong->mlx, solong->win, solong->player, 50, 50);		// window에 img 출력
//	mlx_put_image_to_window(solong->mlx, solong->win, solong->exit, 50, 50);		// window에 img 출력
//	mlx_put_image_to_window(solong->mlx, solong->win, solong->bg, 50, 50);		// window에 img 출력
//	mlx_put_image_to_window(solong->mlx, solong->win, solong->collect, 50, 50);		// window에 img 출력



	/*
	 * mlx_loop : 이벤트 수신하는 함수. 무한루프이므로 함수 마지막에 써야함
	 * mlx_loop_hook : 아무 이벤트도 일어나지 않을 경우 인자로 받았던 함수가 호출됨.
	 *					이벤트 발생 조건 없이 매개변수로 입력된 함수를 무한대로 실행
	 * mlx_hook : 이벤트 생성하는 함수. mlx_key_hook과 달리 키 누르고 있는 상태에서 무한 반복
	 */


	// mlx_hook으로 바꿔보기 : int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void *param);
	//mlx_hook(win, X_KEY_PRESS,)
	mlx_key_hook(solong->win, key_check, solong->win);

	mlx_loop(solong->mlx);



	return (EXIT_SUCCESS);
}

