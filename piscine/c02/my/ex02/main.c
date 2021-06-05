#include <stdio.h>

int	ft_str_is_alpha(char *str);

int		main(void)
{
	char *str_valid;
	char *str_invalid;
	char *str_null;

	str_valid = "Hello";
	str_invalid = "Hell0";
	str_null = "";
	printf("should be 1: %d\n", ft_str_is_alpha(str_valid));
	printf("should be 0: %d\n", ft_str_is_alpha(str_invalid));
	printf("should be 1: %d\n", ft_str_is_alpha(str_null));

	return 0;
}
