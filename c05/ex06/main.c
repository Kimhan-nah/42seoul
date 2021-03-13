#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	printf("1 == %d\n", ft_is_prime(2));
	printf("1 == %d\n", ft_is_prime(3));
	printf("1 == %d\n", ft_is_prime(503));
	printf("1 == %d\n", ft_is_prime(1223));

	printf("0 == %d\n", ft_is_prime(0));
	printf("0 == %d\n", ft_is_prime(1));
	printf("0 == %d\n", ft_is_prime(10));
	printf("0 == %d\n", ft_is_prime(253009));	// 503 * 503
	printf("0 == %d\n", ft_is_prime(1495729));	// 1223 * 1223

	return (0);
}
