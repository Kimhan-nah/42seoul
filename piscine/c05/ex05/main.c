#include <stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	printf("13 == %d\n", ft_sqrt(169));
	printf("14 == %d\n", ft_sqrt(196));
	printf("0 == %d\n", ft_sqrt(197));
	printf("100 == %d\n", ft_sqrt(10000));
	printf("300 == %d\n", ft_sqrt(90000));
	printf("400 == %d\n", ft_sqrt(160000));
	printf("450 == %d\n", ft_sqrt(202500));
	printf("10000 == %d\n", ft_sqrt(100000000));

	return (0);
}
