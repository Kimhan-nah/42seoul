/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:41:56 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/06 05:47:15 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	stopwatch_ms(long long timestamp)
{
	long long ms;

	ms = get_current_ms();
	return (ms - timestamp);
}

long long	get_current_ms()
{
	struct timeval	time;
	long long		current;

	gettimeofday(&time, NULL);
	current = time.tv_sec *  1000 + time.tv_usec / 1000;
	return (current);
}

void	print_state(t_philo *philo, int state)
{
	// alive 한지 확인 후 출력해야 함. 죽었으면 출력하면 안 되고 종료시켜야 함
	pthread_mutex_lock(philo->info->print);
	if (state == grabbing)
		printf("%s%lldms %d has taken a fork\033[0m\n", "\033[34m", stopwatch_ms(philo->timestamp), philo->index);
	else if (state == eating)
		printf("%s%lldms %d is eating\033[0m\n", "\033[32m", stopwatch_ms(philo->timestamp), philo->index);
	else if (state == sleeping)
		printf("%s%lldms %d is sleeping\033[0m\n", "\033[33m", stopwatch_ms(philo->timestamp), philo->index);
	else if (state == thinking)
		printf("%s%lldms %d is thinking\033[0m\n", "\033[35m", stopwatch_ms(philo->timestamp), philo->index);
	pthread_mutex_unlock(philo->info->print);
}

void	go_eat(t_philo *philo)
{
	// 1. left fork lock
	pthread_mutex_lock(philo->left);
	print_state(philo, grabbing);

	// 2. right fork lock
	pthread_mutex_lock(philo->right);
	print_state(philo, grabbing);

	// 3. print
	print_state(philo, eating);

	// 4. eating
	philo->last_eat = get_current_ms();
	while (stopwatch_ms(philo->last_eat) <= philo->info->eat_time)
		usleep(20);		// 무한루프로 인한 성능 저하 막기 위함 (spin lock의 단점)

	// 5. left fork unlock
	pthread_mutex_unlock(philo->left);
	// 6. right fork unlock
	pthread_mutex_unlock(philo->right);
}

void	go_sleep(t_philo *philo)
{
	print_state(philo, sleeping);

	philo->last_sleep = get_current_ms();		// 자기 시작한 시간 저장
	while (stopwatch_ms(philo->last_sleep) <= philo->info->sleep_time)
		usleep(20);
	// print
	print_state(philo, thinking);
}

