/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:34:16 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 20:00:37 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	print_str(char *c);
extern int	is_valid(char *str);
extern int	free_allocations(void);
extern int	g_find_flag;
extern int	**g_condition;
int			g_size = 4;

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid(argv[1]) || g_find_flag == 0)
		{
			print_str("Error\n");
			free_allocations();
			return (0);
		}
		else
			free_allocations();
	}
	else
		print_str("Error\n");
	return (0);
}
