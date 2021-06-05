#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	printf("(-) : %d\n", ft_recursive_factorial(-3));
	printf("0! : %d\n", ft_recursive_factorial(0));
	printf("2! : %d\n", ft_recursive_factorial(2));
	printf("3! : %d\n", ft_recursive_factorial(3));
	printf("5! : %d\n", ft_recursive_factorial(5));

	return (0);
}
