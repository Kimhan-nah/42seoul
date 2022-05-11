/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:36 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/11 17:57:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	is_finish(t_philo *philo, t_info *info)
{
	if (info->must_eat == -1)
		return (false);
	if (info->is_finish[philo->index - 1] == false)
	{
		if (philo->count_eat >= info->must_eat)
		{
			pthread_mutex_lock(info->mutex);
			info->is_finish[philo->index - 1] = true;
			info->count_must_eat++;
			pthread_mutex_unlock(info->mutex);
		}
		if (info->count_must_eat == info->philo_number)
		{
			pthread_mutex_lock(info->mutex);
			info->alive = 2;
			pthread_mutex_unlock(info->mutex);
			return (true);
		}
	}
	return (false);
}

void	monitoring_thread(t_philo *philos, t_info *info)
{
	int			i;
	t_bool		finished;

	i = 0;
	while (stopwatch_ms(philos[i].last_eat) <= info->die_time)
	{
		finished = is_finish(philos + i, info);
		if (finished == true)
			return ;
		if (info->alive)
			return ;
		i++;
		if (i == info->philo_number)
			i = 0;
		usleep(500);
	}
	pthread_mutex_lock(info->mutex);
	if (finished == false)
	{
		info->alive = 1;
		printf("%s%lld %d died \033[0m\n",
			"\033[031m", stopwatch_ms(info->start_time), philos[i].index);
	}
	pthread_mutex_unlock(info->mutex);
}

void	*born_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		usleep(philo->info->eat_time * 500);
	if (philo->info->philo_number == 1)
	{
		go_eat(philo, philo->info);
		return (NULL);
	}
	while (!philo->info->alive)
	{
		go_eat(philo, philo->info);
		go_sleep(philo, philo->info);
	}
	return (NULL);
}

static int	thread_err(pthread_t *tid, t_philo *philos, t_info *info, int i)
{
	pthread_mutex_lock(info->mutex);
	info->alive = 1;
	pthread_mutex_unlock(info->mutex);
	free_resources(tid, philos, info, i);
	return (FAILURE);
}

int	generate_philo(t_philo *philos, t_info *info)
{
	pthread_t	*tid;
	int			i;

	i = 0;
	tid = (pthread_t *)ft_calloc(info->philo_number, sizeof(pthread_t));
	if (!tid)
	{
		free_resources(NULL, philos, info, 0);
		return (FAILURE);
	}
	info->start_time = get_current_ms();
	while (i < info->philo_number)
	{
		pthread_mutex_lock(info->mutex);
		philos[i].last_eat = info->start_time;
		pthread_mutex_unlock(info->mutex);
		if (pthread_create(tid + i, NULL, born_philo, philos + i))
			return (thread_err(tid, philos, info, i));
		i++;
	}
	monitoring_thread(philos, info);
	free_resources(tid, philos, info, info->philo_number);
	return (SUCCESS);
}
