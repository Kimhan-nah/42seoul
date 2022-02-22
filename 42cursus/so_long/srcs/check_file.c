/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/22 14:56:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_valid_file(int argc, char *argv[])
{
	char	*ptr;
	char	*extension;

	if (argc != 2)
		exit_with_error_message("Error\nInvalid Argument");

	ptr = argv[1];
	extension = ".ber";
	if (ft_strlen(ptr) < 5)
		exit_with_error_message("Error\nInvalid file.");
	while (*ptr)
		ptr++;
	ptr -= 4;
	if (ft_strncmp(ptr, extension, 4))
		exit_with_error_message("Error\nInvalid file");
}

static void	is_valid_line(char *line, int col, int *flag)
{
	int count;
	char	*component;
	char	ptr;

	count = 0;
	component = "01CEP";
//	if (!line)
//		exit_with_error_message("Invalid Map.");
	while (*line)
	{
		if (((count == 0 || count  == col - 1) && *line != '1'))
			exit_with_error_message("Error\nInvalid Map. 1");
		ptr = *ft_strchr(component, *line);
		if (!ptr)
			exit_with_error_message("Error\nInvalid Map. 2");
		else if (ptr == 'C')
			flag[0]++;			
		else if (ptr == 'E')
			flag[1]++;			
		else if (ptr == 'P')
			flag[2]++;			
		count++;
		line++;
	}
	if (*line && count != col)
		exit_with_error_message("Error\nInvalid Map. 3");
}

static void	is_valid_wall(char *line, int row, int *col)
{
	while (*line == '1')
	{
		line++;
		if (row == 0)
			(*col)++;
	}
	if (*line)
	{
		printf("%s\n",line);
		exit_with_error_message("Error\nInvalid Map. wall1");
	}

	if (row != 0 && row * (*col) <= 8)
		exit_with_error_message("Error\nInvalid Map. wall2");
	
}

void	parsing(char *file, t_list *map)
{
	int fd;
	int row;
	int col;
	char *line;
	int	flag[3];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_with_error_message("Error\nInvalid file.");
	row = 0;
	col = 0;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (row == 0)
			is_valid_wall(line, row, &col);
		else
			is_valid_line(line, col, flag);
		ft_lstadd_back(&map, ft_lstnew(line));
		row++;
	}
	if (row < 2|| !flag[0] || !flag[1] || !flag[2])
		exit_with_error_message("Error\nInvalid Map. 4");
	if (*line)
		is_valid_wall(line, row, &col);
	else
		is_valid_wall(ft_lstlast(map)->content, row, &col);
}

//int main(int argc, char **argv)
//{
//	t_list	*map;
//	
//	map = 0;
//	// check file extension and argc
//	is_valid_file(argc, argv);
//
//	//parsing and vailidating
//	parsing(argv[1], map);
//
//	return (EXIT_SUCCESS);
//	
//}
