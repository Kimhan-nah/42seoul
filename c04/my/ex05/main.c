#include <stdio.h>

int		ft_atoi_base(int nbr, char *base);

int	main(void)
{
	printf("1e240\n");
	ft_atoi_base(123456, "0123456789abcdef");
	printf("\n===========\n");

	printf("eioopp\n");
	ft_atoi_base(123456, "poneyvif");
	printf("\n===========\n");

	printf("11110001001000000\n");
	ft_atoi_base(123456, "01");
	printf("\n===========\n");

	printf("-1e240\n");	
	ft_atoi_base(-123456, "0123456789abcdef");
	printf("\n===========\n");

	printf("0\n");	
	ft_atoi_base(0, "0123456789abcdef");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_atoi_base(123, "0123453");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_atoi_base(123, "012+3");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_atoi_base(123, "");
	printf("\n===========\n");

	return (0);
}
