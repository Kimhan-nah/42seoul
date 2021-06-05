#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("-1234567 : %d\n", ft_atoi("---+-++-1234567"));
	printf("0 : %d\n", ft_atoi("	--+- ++-1234567"));
	printf("1234567 : %d\n", ft_atoi("	--+-++-1234567abc"));
	printf("0 : %d\n", ft_atoi("--+-++- 1234567"));
	printf("-1234 : %d\n", ft_atoi("	--+-++--1234ab567"));
	printf("0 : %d\n", ft_atoi("	--+-++--bd1234ab567"));



	return (0);
}
