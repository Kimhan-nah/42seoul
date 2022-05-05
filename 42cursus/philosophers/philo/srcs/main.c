/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 12:59:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (FAILURE);
	philo = parsing(argc, argv);
	if (!philo)
		return (FAILURE);
	if (born_philo(philo, philo->info) == FAILURE)
		return (FAILURE);

	// monitoring in main thread
	monitoring_thread();

	// thread 동기화 처리
	// thread 종료 (자원 해제) join 
	// destroy ? 

	return (SUCCESS);
}
