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
	void	*img;
	int	width;
	int	height;
	
	mlx = mlx_init();
	if (!mlx)
		exit(EXIT_FAILURE);
	win = mlx_new_window(mlx, 500, 500, "mlx_test");
	if (!win)
		exit(EXIT_FAILURE);

	img = mlx_xpm_file_to_image(mlx, "../img/asteroid-1.xpm", &width, &height);		// img 포인터로 저장
	if (!img)
		exit_with_message("Error\nimg error");
	//mlx_put_image_to_window(mlx, win, img, 50, 50);		// window에 img 출력

	mlx_key_hook(win, key_check, win);

	mlx_loop(mlx);


	return (EXIT_SUCCESS);
}
