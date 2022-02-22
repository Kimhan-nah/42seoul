/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/22 11:30:04 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_valid_file(int argc, char *argv[])
{
	char	*ptr;
	char	*extension;
	int		i;

	if (argc != 2)
		exit_with_error_message("Invalid Argument");

	ptr = argv[1];
	extension = ".ber";
	i = 0;
	if (ft_strlen(ptr) < 5)
		exit_with_error_message("Invalid file.");
	while (*ptr)
		ptr++;
	ptr -= 4;
	while (*ptr)
	{
		if (ptr[i] != extension[i])
			exit_with_error_message("Invalid file extension. (.ber)");
		i++;
	}
}

static int	is_valid_line(char *line, int row, int *col)
{
	int count;
	char	*component;

	count = 0;
	component = "01CEP";
//	if (!line)
//		exit_with_error_message("Invalid Map.");
	while (row == 0 && *line == '1')
	{
		line++;
		(*col)++;
		count++;
	}
	while (row != 0 && *line)
	{
		if (!ft_strchr(component, *line))
			return (1);
		count++;
	}
	if (*col < 2 || count != *col || *line)
		return (1);
	return (0);

}

void	parsing(char *file, t_list *map)
{
	int fd;
	int row;
	int col;
	char *line;

	fd = open(file, O_RDONLY);
	row = 0;
	col = 0;
	if (fd == -1)
		exit_with_error_message("Invalid file.");
	while (get_next_line(fd, &line) > -1)
	{
		if (is_valid_line(line, row, &col))
			exit_with_error_message("Invalid Map.");
		ft_lstadd_back(&map, ft_lstnew(line));
		row++;
	}
	if (row < 2)
		exit_with_error_message("Invalid Map.");
	// 마지막 줄 valid check
	if (is_valid_line(ft_lstlast(map)->content, 0, &col))
		exit_with_error_message("Invalid Map.");
}
