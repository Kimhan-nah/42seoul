#include <stdio.h>

extern char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(void)
{
	printf("-1111111111111111111111111111111 == %s\n", ft_convert_base("  ---7fffffff", "0123456789abcdef", "01"));
	printf("-74565 == %s\n", ft_convert_base("    +-+--12345", "0123456789abcdef", "0123456789"));
	printf("74565 == %s\n", ft_convert_base("    -+-+--12345", "0123456789abcdef", "0123456789"));
	printf("-1023  == %s\n", ft_convert_base("    -+-+-0001023", "0123456789", "0123456789"));
	printf("-255 == %s\n", ft_convert_base("    -+-+-ff-f", "0123456789abcdef", "0123456789"));

	// wrong number -> return 0
	printf("0 == %s\n", ft_convert_base("    +-+--0", "0123456789abcdef", "0123456789"));
	printf("0 == %s\n", ft_convert_base("    +-+--234", "01", "0123456789"));

	// wrong base -> return null
	printf("(nothing) == %s\n", ft_convert_base("    +-+--0", "0123456789 abcdef", "0123456789"));
	printf("(nothing) == %s\n", ft_convert_base("    +-+--234", "01", "0+"));

	printf("-80000000 == %s\n", ft_convert_base("    +-+--2147483648", "0123456789", "0123456789abcdef"));
	return (0);
}
