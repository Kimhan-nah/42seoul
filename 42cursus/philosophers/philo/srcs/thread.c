/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:36 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/08 20:36:23 by hannah           ###   ########.fr       */
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
	t_bool		finished;;

	i = 0;
	while (stopwatch_ms(philos[i].last_eat) <= info->die_time)
	{
		finished = is_finish(philos + i,info);
		if (finished == true)
			return ;
		i = (i + 1) % info->philo_number;
		usleep(500);
	}
	pthread_mutex_lock(info->mutex);
	if (finished != false)
		printf("must eat !!!!!!\n");
	else
	{
		info->alive = 1; 
		printf("%s%lld %d died \033[0m\n", "\033[031m", stopwatch_ms(info->start_time), philos[i].index);
	}
	pthread_mutex_unlock(info->mutex);
}

void	*born_philo(void *arg)
{
	t_philo *philo;

	// 스레드가 모두 생성된 경우에만 진행
	
	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		usleep(philo->info->eat_time * 500);		// usleep(microseconds), info->eat_time : milisecocnds
	while (!philo->info->alive)
	{
		go_eat(philo, philo->info);
		go_sleep(philo, philo->info);
	}
	return NULL;
}

int	generate_philo(t_philo *philos, t_info *info)
{
	int i;
	pthread_t	*tid;

	i = 0;
	tid = (pthread_t *)ft_calloc(info->philo_number, sizeof(pthread_t));
	if (!tid)
	{
		exit_free(philos);
		return (FAILURE);
	}
	info->start_time = get_current_ms();
	while (i < info->philo_number)
	{
		pthread_mutex_lock(info->mutex);
		philos[i].last_eat = info->start_time;
		if (pthread_create(tid + i, NULL, born_philo, philos + i))
			return thread_error();
		i++;
		pthread_mutex_unlock(info->mutex);
	}
	monitoring_thread(philos, philos->info);
	i = 0;
	while (i < info->philo_number)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->philo_number)
	{
		pthread_mutex_destroy(philos[i].left);
		i++;
	}
	pthread_mutex_destroy(info->mutex);
	free(tid);
	free(info);
	free(philos);
	return (SUCCESS);
}
