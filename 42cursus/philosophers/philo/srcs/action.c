/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:41:56 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/08 12:20:38 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	stopwatch_ms(long long start_time)
{
	long long	current;

	current = get_current_ms();
	return (current - start_time);
}

long long	get_current_ms()
{
	struct timeval	time;
	long long		current;

	gettimeofday(&time, NULL);
	current = time.tv_sec *  1000 + time.tv_usec / 1000;
	return (current);
}

void	print_state(t_philo *philo, t_info *info, int state)
{
	pthread_mutex_lock(info->mutex);
	if (info->alive == 0)
	{
		if (state == grabbing)
			printf("%s%lldms %d has taken a fork\033[0m\n", "\033[34m", stopwatch_ms(info->start_time), philo->index);
		else if (state == eating)
			printf("%s%lldms %d is eating\033[0m\n", "\033[32m", stopwatch_ms(info->start_time), philo->index);
		else if (state == sleeping)
			printf("%s%lldms %d is sleeping\033[0m\n", "\033[33m", stopwatch_ms(info->start_time), philo->index);
		else if (state == thinking)
			printf("%s%lldms %d is thinking\033[0m\n", "\033[35m", stopwatch_ms(info->start_time), philo->index);
	}
	pthread_mutex_unlock(info->mutex);
}

void	go_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(philo->left);
	print_state(philo, info, grabbing);
	pthread_mutex_lock(philo->right);
	print_state(philo, info, grabbing);
	print_state(philo, info, eating);
	philo->last_eat = get_current_ms();
	pthread_mutex_lock(info->mutex);
	(philo->count_eat)++;
	pthread_mutex_unlock(info->mutex);
	while (!info->alive && stopwatch_ms(philo->last_eat) <= info->eat_time)
		usleep(500);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	go_sleep(t_philo *philo, t_info *info)
{
	print_state(philo, info, sleeping);
	philo->last_sleep = get_current_ms();
	while (!info->alive && stopwatch_ms(philo->last_sleep) <= info->sleep_time)
		usleep(500);
	print_state(philo, info, thinking);
//	usleep(50);
}

