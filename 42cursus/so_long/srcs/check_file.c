/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/25 12:34:17 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_file(int argc, char *argv[])
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
	if (*line && count != col)
		exit_with_message("Error\nInvalid solong. 3");
}

static void	check_wall(char *line, t_solong *solong)
{
	while (*line == '1')
	{
		line++;
		if (solong->row == 0)
			(solong->col)++;
	}
	if (*line)
	{
		printf("%s\n",line);
		exit_with_message("Error\nInvalid solong. wall1");
	}

	if (solong->row != 0 && solong->row * solong->col <= 8)
		exit_with_message("Error\nInvalid solong. wall2");
	
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
			check_wall(line, solong);
		else
			check_line(line, solong->col, flag);
		ft_lstadd_back(&(solong->map), ft_lstnew(line));
		solong->row++;
	}
	close(fd);
	if (solong->row < 2|| !flag[0] || !flag[1] || !flag[2])
		exit_with_message("Error\nInvalid solong. 4");
	if (*line)
		check_wall(line, solong);
	else
		check_wall(ft_lstlast(solong->map)->content, solong);
}

//int main(int argc, char **argv)
//{
//	t_list	*solong;
//	
//	solong = 0;
//	// check file extension and argc
//	is_valid_file(argc, argv);
//
//	//parsing and vailidating
//	parsing(argv[1], solong);
//
//	return (EXIT_SUCCESS);
//	
//}
