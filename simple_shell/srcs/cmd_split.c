#include "../includes/pipex.h"

static char	quotes_marks(char **start, char **end)
{
	char	chr;

	if (**start != '\'' && **start != '\"')
		chr = ' ';
	else
	{
		chr = **start;
		(*end)++;
		(*start)++;
	}
	return (chr);
}

char	*strcut(char *start, char *end)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = end - start;
	ret = (char *)calloc(len + 1, sizeof(char));
	while (i < len)
	{
		ret[i] = *start;
		i++;
		start++;
	}
	return (ret);
}

void	cmd_split(char **ret, char *str)
{
	char	*start;
	char	*end;
	char	chr;
	int		i;

	start = str;
	end = str;
	i = 0;
	while (*end)
	{
		chr = quotes_marks(&start, &end);
		while (*end != chr && *end)
			end++;
		if (end - start > 0)
		{
			ret[i] = strcut(start, end);
			i++;
		}
		while (*end == ' ')
			end++;
		start = end;
	}
}

int	cmd_count(char *str)
{
	char	*start;
	char	*end;
	char	chr;
	int		count;

	start = (char *)str;
	end = (char *)str;
	count = 0;
	while (*end)
	{
		chr = quotes_marks(&start, &end);
		while (*end != chr && *end)
			end++;
		if (end - start > 0)
			count++;
		while (*end == ' ')
			end++;
		start = end;
	}
	return (count);
}
