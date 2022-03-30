#include "../includes/pipex.h"

static int	is_set(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx] && set[idx] != c)
		idx++;
	if (set[idx] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		idx;
	int		start;
	int		end;

	idx = 0;
	start = 0;
	if (!s1)
		exit_msg("ft_strtrim");
	end = strlen(s1) - 1;
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && start < end)
		end--;
	strtrim = (char *)calloc(end - start + 2, sizeof(char));
	if (!strtrim)
		exit_msg("ft_strtrim");
	while (start <= end)
		strtrim[idx++] = s1[start++];
	return (strtrim);
}

void	putendl_fd(char *s, int fd)
{
	char	*ptr;

	ptr = s;
	if (!s)
		return ;
	while (*ptr)
	{
		write(fd, ptr, 1);
		ptr++;
	}
	write(fd, "\n", 1);
}

void	exit_msg(char *msg)
{
	putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;
	int		idx;
//	int		p_idx;

	if (!s1 || !s2)
		exit_msg("libft : strjoin");
	idx = strlen(s1);
	len = idx + strlen(s2);
//	p_idx = 0;
	strjoin = (char *)calloc(len + 1, sizeof(char));
	memcpy(strjoin, s1, strlen(s1));
	memcpy(strjoin + strlen(s1), s2, strlen(s2));
	return (strjoin);
}
