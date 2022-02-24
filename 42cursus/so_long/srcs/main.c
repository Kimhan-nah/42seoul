/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:52:59 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/24 15:34:58 by hannkim          ###   ########.fr       */
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
	t_list	map;
	void	*img;
	

	// check file extension and argc
	check_file(argc, argv);

	//parsing and vailidating
	parsing(argv[1], &map);

	mlx = mlx_init();
	if (!mlx)
		exit_with_message("Error\nFail MLX");
	win = mlx_new_window(mlx, 500, 500, "mlx_test");
	if (!win)
		exit_with_message("Error\nFail WIN");
	//init mlx and mlx_image
	//draw 



	// mlx 이미지 생성 : void *mlx_new_image(void *mlx_ptr, int width, int height);
	img = mlx_new_image(mlx, 200, 200);

	// mlx 이미지 파일 가져오기 : void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	
	// mlx 이미지 출력 : int mlx_put_image_to_window(void *(mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);


	/*
	 * mlx_loop : 이벤트 수신하는 함수. 무한루프이므로 함수 마지막에 써야함
	 * mlx_loop_hook : 아무 이벤트도 일어나지 않을 경우 인자로 받았던 함수가 호출됨.
	 *					이벤트 발생 조건 없이 매개변수로 입력된 함수를 무한대로 실행
	 * mlx_hook : 이벤트 생성하는 함수. mlx_key_hook과 달리 키 누르고 있는 상태에서 무한 반복
	 */


	// mlx_hook으로 바꿔보기 : int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void *param);
	//mlx_hook(win, X_KEY_PRESS,)
	mlx_key_hook(win, key_check, win);

	mlx_loop(mlx);







	return (EXIT_SUCCESS);
}

