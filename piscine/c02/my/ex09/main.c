#include <stdio.h>

char *ft_strcapitalize(char *str);

int main()
{
	char a[] ="salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(a));

	return 0;
}
