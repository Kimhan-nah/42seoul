#include <unistd.h>

void	ft_print_combn(int n);

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n\n", 2);
	ft_print_combn(3);
	write(1, "\n\n", 2);
	ft_print_combn(9);

	return (0);
}
