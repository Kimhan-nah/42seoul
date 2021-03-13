#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int main()
{
	printf("%d\n", ft_strcmp("abcd", "abcdef"));		// -101
	printf("%d\n", ft_strcmp("abcdef", "abcd"));		// 101
	printf("%d\n", ft_strcmp("abcd", "abcd"));		// 0
	printf("%d\n", ft_strcmp("abcd", "abcf"));		// d < f -> d-f = -1

	return 0;
}
