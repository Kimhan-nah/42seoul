#include <stdio.h>

char	*ft_strstr(char *str, char *to_finc);

int	main(void)
{
	char str1[] = "aac";
	//char str2[] = "";

	printf("%s\n", ft_strstr(str1, "ac"));	// hello  bb
//	printf("%s\n", ft_strstr(str1, "bye"));	// llo  bb
//	printf("%s\n", ft_strstr(str1, "hi"));	// ab hello  bb
	return (0);
}
