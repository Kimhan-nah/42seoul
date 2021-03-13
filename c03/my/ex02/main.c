#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char dest[100] = "123";

	printf("%s\n", ft_strcat(dest,"456"));
	printf("%s\n", ft_strcat(dest, "789abc"));

	return (0);
}
