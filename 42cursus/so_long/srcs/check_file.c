/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/28 18:29:18 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_line(char *line, int col, int *flag)
{
	int count;
	char	*component;
	char	ptr;

	count = 0;
	component = "01CEP";
//	if (!line)
//		exit_with_message("Invalid solong.");
	while (*line)
	{
		if (((count == 0 || count  == col - 1) && *line != '1'))
			exit_with_message("Error\nInvalid solong. 1");
		ptr = *ft_strchr(component, *line);
		if (!ptr)
			exit_with_message("Error\nInvalid solong. 2");
		else if (ptr == 'C')
			flag[0]++;			
		else if (ptr == 'E')
			flag[1]++;			
		else if (ptr == 'P')
			flag[2]++;			
		count++;
		line++;
	}
}

static void	check_wall(char *line)
{
	while (*line == '1')
		line++;
	if (*line)
	{
		printf("%s\n",line);
		exit_with_message("Error\nInvalid solong. wall1");
	}
}

void	check_mapsize(char *file, t_solong *solong)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_message("Error\nInvalid file.");
	while (get_next_line(fd, &line) > 0)
	{
		if (solong->row == 0)
			solong->col = ft_strlen(line);
		else if (ft_strlen(line) != solong->col)
			exit_with_message("Error\nInvalid map size. It is not square.");
		solong->row++;
	}
	close(fd);
	if (*line)
	{
		if (ft_strlen(line) != solong->col)
			exit_with_message("Error\nInvalid map size. It is not square.");
		solong->row++;
	}
	if (solong->row < 3 || solong->col < 3 || solong->row * solong->col < 15)
		exit_with_message("Error\nInvalid map size.");
}

void	check_arg(int argc, char *argv[])
{
	char	*ptr;
	char	*extension;

	if (argc != 2)
		exit_with_message("Error\nInvalid Argument");

	ptr = argv[1];
	extension = ".ber";
	if (ft_strlen(ptr) < 5)
		exit_with_message("Error\nInvalid file.");
	while (*ptr)
		ptr++;
	ptr -= 4;
	if (ft_strncmp(ptr, extension, 4))
		exit_with_message("Error\nInvalid file");
}

void	parsing(char *file, t_solong *solong)
{
	int fd;
	char *line;
	int	flag[3];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_message("Error\nInvalid file.");
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (solong->row == 0)
			check_wall(line);
		else
			check_line(line, solong->col, flag);
		//ft_lstadd_back(&(solong->map), ft_lstnew(line));
	}
	close(fd);
	if (solong->row < 2|| !flag[0] || !flag[1] || !flag[2])
		exit_with_message("Error\nInvalid solong. 4");
	check_wall((solong->map)[solong->row - 1]);
}
