#include <stdio.h>

int	*ft_range(int min, int max);

int	main()
{
	for (int i = 0 ; i < 7; i++)
		printf("%d ", ft_range(3, 10)[i]);

	return (0);
}
