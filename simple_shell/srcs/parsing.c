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

static char	*strcut(char *start, char *end)
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

static void	cmd_split(char **ret, char *str)
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

static int	cmd_count(char *str)
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

static char	**cmd_parsing(char *cmd)
{
	char	*str;
	char	**ret;
	int		len;

	str = strtrim(cmd, " \n");		// alloc
	len = cmd_count(str);
	ret = (char **)calloc(len + 1, sizeof(char *));
	cmd_split(ret, str);
	free(str);
	return (ret);
}

void	parsing(t_info *info, char *str)
{
	char	*ptr = str;
	char	*cmd;
	
	while (*ptr)
	{
		if (*ptr == '|')
		{
			cmd = strcut(str, ptr);
			info->cmds[0] = cmd_parsing(cmd);
			free(cmd);

			cmd = strcut(ptr + 1, str + strlen(str));
			info->cmds[1] = cmd_parsing(cmd);
			free(cmd);

			return ;
		}
		ptr++;
	}
	info->cmds[0] = cmd_parsing(str);
}
