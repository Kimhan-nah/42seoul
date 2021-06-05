#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{

	printf("%d\n", ft_strncmp("abcd", "abcd", 5));	// 0
	printf("%d\n", ft_strncmp("abcdefg", "abcd", -1));	//101
	printf("%d\n", ft_strncmp("abcd", "abcdefg", -1));	//-101
	printf("%d\n", ft_strncmp("abcdefg", "abcd", 5));	//101
	printf("%d\n", ft_strncmp("abcd", "abcdefg", 5));	//-101

	return 0;
}
