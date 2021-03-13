#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char dest1[100] = "123";
	char dest2[100] = "123";
	char dest3[100] = "123";
	char dest4[100] = "123";
	char dest5[100] = "123";
	char dest6[100] = "123";
	char dest7[100] = "123";
	char dest8[100] = "123";
	char dest9[100] = "123";
	char *src = "A456";

	printf("dest : %s,   src : %s\n", dest1, src);

	printf("size : 0 -> return : %d , dest : %s\n", ft_strlcat(dest1, src, 0), dest1);
	printf("size : 2 -> return : %d , dest : %s\n", ft_strlcat(dest2, src, 2), dest2);
	printf("size : 3 -> return : %d , dest : %s\n", ft_strlcat(dest3, src, 3), dest3);
	printf("size : 4 -> return : %d , dest : %s\n", ft_strlcat(dest4, src, 4), dest4);
	printf("size : 5 -> return : %d , dest : %s\n", ft_strlcat(dest5, src, 5), dest5);
	printf("size : 6 -> return : %d , dest : %s\n", ft_strlcat(dest6, src, 6), dest6);
	printf("size : 7 -> return : %d , dest : %s\n", ft_strlcat(dest7, src, 7), dest7);
	printf("size : 8 -> return : %d , dest : %s\n", ft_strlcat(dest8, src, 8), dest8);
	printf("size : 9 -> return : %d , dest : %s\n", ft_strlcat(dest9, src, 9), dest9);
	
	
	return (0);
}
