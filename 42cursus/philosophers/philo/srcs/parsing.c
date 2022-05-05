/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 12:59:01 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	initialize(t_philo *philo, t_info *info)
{
	int i;
	pthread_mutex_t	*fork;

	i = 0;
	while (i < info->philo_number)
	{
		fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (!fork)
			return (FAILURE);
		philo[i].left = fork;
		philo[(i + 1) % info->philo_number].right = fork;

		philo[i].eat_cnt = info->eat_time;
		philo[i].die_cnt = info->die_time;
		philo[i].sleep_cnt = info->sleep_time;
		philo[i].info = info;
		philo[i].index = i + 1;
		i++;
	}
	return (SUCCESS);
}

t_philo	*parsing(int argc, char **argv)
{
	t_philo *philo;
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

	philo = (t_philo *)ft_calloc(info->philo_number, sizeof(t_philo));
	if (!philo)		// info free 해야 함
	{
		free(info);
		return (NULL);
	}
	if (initialize(philo, info))	// philo, info 만들어졌고, mutex 할당 실패했을 경우 free 필요함
		return (exit_free(philo));
	return (philo);
}
