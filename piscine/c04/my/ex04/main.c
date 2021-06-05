#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	printf("1e240\n");
	ft_putnbr_base(123456, "0123456789abcdef");
	printf("\n===========\n");

	printf("eioopp\n");
	ft_putnbr_base(123456, "poneyvif");
	printf("\n===========\n");

	printf("11110001001000000\n");
	ft_putnbr_base(123456, "01");
	printf("\n===========\n");

	printf("-1e240\n");	
	ft_putnbr_base(-123456, "0123456789abcdef");
	printf("\n===========\n");

	printf("0\n");	
	ft_putnbr_base(0, "0123456789abcdef");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_putnbr_base(123, "0123453");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_putnbr_base(123, "012+3");
	printf("\n===========\n");

	printf("(nothing)\n");	
	ft_putnbr_base(123, "");
	printf("\n===========\n");
	
	printf("-2147483647\n");	
	ft_putnbr_base(-2147483647, "0123456789");
	printf("\n===========\n");

	printf("-2147483648\n");
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n===========\n");

	return (0);
}
