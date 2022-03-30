#include "../includes/pipex.h"

static char	**cmd_parsing(char *cmd)
{
	char	*str;
	char	**ret;
	int		len;

	str = ft_strtrim(cmd, " \n");		// alloc
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
