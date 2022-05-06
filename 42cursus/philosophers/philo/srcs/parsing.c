/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/06 15:35:35 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	initialize(t_philo *philos, t_info *info)
{
	int i;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;

	i = 0;
	while (i < info->philo_number)
	{
		fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (!fork)
			return (FAILURE);
		if (pthread_mutex_init(fork, NULL))		// mutex 초기화
			return (FAILURE);
		philos[i].left = fork;
		philos[(i + 1) % info->philo_number].right = fork;
		philos[i].info = info;
		philos[i].index = i + 1;
		i++;
	}
	print = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(print, NULL))		// mutex 초기화 에러 처리 해야 하는지?
		return (FAILURE);
	info->print = print;
	return (SUCCESS);
}

t_philo	*parsing(int argc, char **argv)
{
	t_philo *philos;
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)		// free 필요 없음
		return (NULL);
	info->philo_number = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);

	philos = (t_philo *)ft_calloc(info->philo_number, sizeof(t_philo));
	if (!philos)		// info free 해야 함
	{
		free(info);
		return (NULL);
	}
	if (initialize(philos, info))	// philo, info 만들어졌고, mutex 할당 실패했을 경우 free 필요함
		return (exit_free(philos));
	return (philos);
}
