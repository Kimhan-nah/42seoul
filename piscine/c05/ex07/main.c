#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("3 == %d\n", ft_find_next_prime(3));
	printf("5 == %d\n", ft_find_next_prime(4));
	printf("503 == %d\n", ft_find_next_prime(500));
	printf("1223 == %d\n", ft_find_next_prime(1218));
	printf("1597 == %d\n", ft_find_next_prime(1584));
	printf("7919 == %d\n", ft_find_next_prime(7908));
	
	return (0);
}
