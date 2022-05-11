/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/11 17:56:51 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_bool	is_valid(t_info *info, int argc)
{
	if (info->philo_number < 1 || info->die_time < 1 || info->eat_time < 1
		|| info->sleep_time < 1)
	{
		free_resources(NULL, NULL, info, 0);
		return (false);
	}
	if (argc == 6 && info->must_eat < 1)
		return (false);
	return (true);
}

static int	initialize(t_philo *philos, t_info *info)
{
	int				i;
	pthread_mutex_t	*fork;

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
	info->mutex = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!info->mutex || pthread_mutex_init(info->mutex, NULL))
	{
		free_resources(NULL, philos, info, 0);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	string_to_int(int argc, char **argv, t_info *info)
{
	info->philo_number = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 5)
		info->must_eat = -1;
	else if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		info->is_finish = (t_bool *)ft_calloc(info->philo_number,
				sizeof(t_bool));
		if (!info->is_finish)
		{
			free(info);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

t_philo	*parsing(int argc, char **argv)
{
	t_philo	*philos;
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info || string_to_int(argc, argv, info) == FAILURE
		|| is_valid(info, argc) == false)
		return (NULL);
	philos = (t_philo *)ft_calloc(info->philo_number, sizeof(t_philo));
	if (!philos)
	{
		free_resources(NULL, NULL, info, 0);
		return (NULL);
	}
	if (initialize(philos, info))
		return (NULL);
	return (philos);
}
