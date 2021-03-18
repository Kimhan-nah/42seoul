#include <stdio.h>

char	**ft_split(char *str, char *charset);

int		main()
{
	char *str = "a,bdcc, da";
	char *charset = "";

	ft_split(str, charset);
	
	return 0;
}
