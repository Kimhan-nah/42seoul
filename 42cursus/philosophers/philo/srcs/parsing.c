/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/08 09:54:36 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	initialize(t_philo *philos, t_info *info)
{
	int				i;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*mutex;

	i = 0;
	while (i < info->philo_number)
	{
		fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (!fork)
			return (FAILURE);
		if (pthread_mutex_init(fork, NULL))
			return (FAILURE);
		philos[i].left = fork;
		philos[(i + 1) % info->philo_number].right = fork;
		philos[i].info = info;
		philos[i].index = i + 1;
		i++;
	}
	mutex = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(mutex, NULL))
		return (FAILURE);
	info->mutex = mutex;
	return (SUCCESS);
}

t_philo	*parsing(int argc, char **argv)
{
	t_philo *philos;
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->philo_number = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		info->is_finish = (t_bool *)ft_calloc(info->philo_number, sizeof(t_bool));
	}
	else
		info->must_eat = -1;
	philos = (t_philo *)ft_calloc(info->philo_number, sizeof(t_philo));
	if (!philos)
	{
		free(info);
		return (NULL);
	}
	if (initialize(philos, info))
		return (exit_free(philos));
	return (philos);
}
