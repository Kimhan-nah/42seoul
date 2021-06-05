#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("%ld\n", strlen("123456789"));
	printf("%ld\n", strlen(""));


	printf("==========\n");
	printf("%d\n", ft_strlen("123456789"));
	printf("%d\n", ft_strlen(""));

	return (0);
}
