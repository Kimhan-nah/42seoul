/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 21:04:49 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_info *info;
	t_philo	*philo;

	if (argc != 5)
		return (FAILURE);
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		return (FAILURE);
	philo = parsing(argv, info);
	if (!philo)
	{
		free(info);
		return (FAILURE);
	}
	if (generate_philo(philo, info) == FAILURE)
	{
		free(philo);
		free(info);
		return (FAILURE);
	}

	// monitoring in main thread
	monitoring_thread();

	// thread 동기화 처리
	// thread 종료 (자원 해제) join 
	// destroy ? 

	return (SUCCESS);
}
