#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("0^0 : %d\n", ft_iterative_power(0, 0));
	printf("3^4 : %d\n", ft_iterative_power(3, 4));
	printf("3^0 : %d\n", ft_iterative_power(3, 0));
	printf("3^(-2) : %d\n", ft_iterative_power(3, -2));
	printf("(-3)^3 : %d\n", ft_iterative_power(-3, 3));

	return (0);
}
