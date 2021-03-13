#include <unistd.h>
#include <stdio.h>

void	print(char **argv)
{
	int i;
	int j;

 	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int i;
	int j;
	char *tmp;

	while (argc - 1 > 0)
	{
		i = 1;
		while (i < argc - 1)
		{
			j = 0;
			while (argv[i][j] == argv[i + 1][j])
				j++;
			if (argv[i][j] > argv[i + 1][j])
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		argc--;
	}
	print(argv);
	return (0);
}
