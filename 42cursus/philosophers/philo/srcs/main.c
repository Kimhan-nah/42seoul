/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/11 18:13:51 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_philo		*philos;

	if (argc != 5 && argc != 6)
	{
		printf("Error. Invalid argc\n");
		return (FAILURE);
	}
	philos = parsing(argc, argv);
	if (!philos)
	{
		printf("Error in parsing.\n");
		return (FAILURE);
	}
	if (generate_philo(philos, philos->info) == FAILURE)
	{
		printf("Error in generate_philo\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
