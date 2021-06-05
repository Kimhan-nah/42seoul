#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int n);

int	main(void)
{
	char dest[100] = "123";
	char src[] = "456";

	printf("%s\n", strncat(dest,src, 1));
	printf("%s\n", ft_strncat(dest, "789abc", 8));

	return (0);
}
