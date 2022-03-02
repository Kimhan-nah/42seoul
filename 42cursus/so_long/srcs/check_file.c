/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/03 07:55:09 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_components(char *line, t_solong *solong, \
		unsigned int i, unsigned int j)
{
	char	*component;
	char	*ptr;

	component = "01CEP";
	ptr = ft_strchr(component, *line);
	if (!ptr)
		exit_with_message("Error\nInvalid solong. 2");
	else if (*ptr == 'C')
		(solong->flag)[0]++;
	else if (*ptr == 'E')
		(solong->flag)[1]++;
	else if (*ptr == 'P')
	{
		(solong->flag)[2]++;
		solong->player.x = i;
		solong->player.y = j;
	}
}

static void	check_line(char *line, t_solong *solong, unsigned int i)
{
	unsigned int	j;

	j = 0;
	if (!line)
		exit_with_message("Error\ncheck_line");
	while (*line)
	{
		if ((j == 0 || j + 1 == solong->col) && *line != '1')
			exit_with_message("Error\nInvalid solong. 1");
		check_components(line, solong, i, j);
		j++;
		line++;
	}
}

static void	check_wall(char **map, unsigned int row, unsigned int col)
{
	char			*top_wall;
	char			*bottom_wall;
	unsigned int	i;

	top_wall = map[0];
	bottom_wall = map[row - 1];
	i = 0;
	while (i < col)
	{
		if (top_wall[i] != '1' || bottom_wall[i] != '1')
			exit_with_message("Error\nInvalid map wall");
		i++;
	}
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
	int				fd;
	unsigned int	i;
	char			*line;

	fd = open(file, O_RDONLY);
	i = 0;
	if (fd < 0)
		exit_with_message("Error\nInvalid file.");
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line, solong, i);
		solong->map[i] = line;
		i++;
	}
	close(fd);
	if (!(solong->flag)[0] || !(solong->flag)[1] || (solong->flag)[2] != 1)
		exit_with_message("Error\nInvalid solong. 4");
	if (*line)
		solong->map[i] = line;
	check_wall(solong->map, solong->row, solong->col);
}
