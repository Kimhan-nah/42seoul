#include <stdio.h>

void	ft_putnbr(int nb);

int main()
{
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(2147483647);

	return 0;
}
