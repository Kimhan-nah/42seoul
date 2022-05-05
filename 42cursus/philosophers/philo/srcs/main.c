/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 18:49:41 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (FAILURE);
	philos = parsing(argc, argv);
	if (!philos)
		return (FAILURE);
	if (generate_philo(philos, philos->info) == FAILURE)
		return (FAILURE);


	// thread 동기화 처리
	// thread 종료 (자원 해제) join 
	// destroy ? 

	return (SUCCESS);
}
