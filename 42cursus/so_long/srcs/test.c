#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int				fd;
	unsigned int	i;
	char			*line;

	int tmp = 0;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd < 0)
		exit(0);
//		exit_with_message("Error\nInvalid file.");
	while ((tmp = get_next_line(fd, &line)) > 0)
	{
		i++;
		free(line);
	}
	printf("tmp : %d\n", tmp);
	printf("line : %s\n", line);
	printf("line : %d\n", *line);
	while (1);


	return 0;
}
