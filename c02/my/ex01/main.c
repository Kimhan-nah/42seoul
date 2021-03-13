#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	char *src;
	char dest1[20];
	char dest2[20];

	src = "Hello World";
	printf("===CASE1===\n");
	printf("base   : %s\n", src);
	strncpy(dest1, src, 8);
	printf("cpy    : %s\n", dest1);
	ft_strncpy(dest2, src, 8);
	printf("ft_cpy : %s\n", dest2);


	return 0;
}
