/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:31:38 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/19 17:16:04 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	push_back_using_read(char **backup, int fd)
{
	int		ret;
	int		len;
	char	*tmp;

	tmp = *backup;
	len = ft_strlen(*backup);
	*backup = (char *)malloc(len + BUFFER_SIZE + 1);
	if (!*backup)
		return (-1);
	ft_memcpy(*backup, tmp, len);
	ret = read(fd, *backup + len, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	(*backup)[len + ret] = 0;
	free(tmp);
	tmp = 0;
	return (ret);
}

static int	get_line(char **line, char **backup)
{
	char	*loc_nl;
	char	*tmp;

	tmp = *backup;
	loc_nl = ft_strchr(*backup, '\n');
	*loc_nl = 0;
	*line = ft_strdup(*backup);
	if (!*line)
		return (-1);
	*backup = ft_strdup(loc_nl + 1);
	if (!*backup)
		return (-1);
	free(tmp);
	tmp = 0;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char			*backup;
	int					ret;

	if (fd < 0 || fd > OPEN_MAX || !line || (BUFFER_SIZE < 1) \
			|| read(fd, backup, 0) == -1)
		return (-1);
	while (!ft_strchr(backup, '\n'))
	{
		ret = push_back_using_read(&backup, fd);
		if (ret <= 0)
			break ;
	}
	if (ret == -1)
		return (-1);
	if (ft_strchr(backup, '\n') != NULL)
		return (get_line(line, &backup));
	*line = ft_strdup(backup);
	if (!*line)
		return (-1);
	free(backup);
	backup = 0;
	return (0);
}
