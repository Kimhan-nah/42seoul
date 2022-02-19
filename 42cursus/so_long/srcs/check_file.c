/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:32 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/19 17:48:48 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	isValidFile(int argc, char *argv[])
{
	char	*ptr;
	char	*extension;
	int		i;

	if (argc != 2)
		exitWithErrorMessage("Invalid Argument");

	ptr = argv[1];
	extension = ".ber";
	i = 0;
	if (ft_strlen(ptr) < 5)
		exitWithErrorMessage("Invalid file.");
	while (*ptr)
		ptr++;
	ptr -= 4;
	while (*ptr)
	{
		if (ptr[i] != extension[i])
			exitWithErrorMessage("Invalid file extension. (.ber)");
		i++;
	}
}

void	parsing(char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exitWithErrorMessage("Invalid file.");
	while (get_next_line(fd, &line) > -1)
	{

	}
}
