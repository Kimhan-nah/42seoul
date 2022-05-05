/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:41:56 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 18:50:48 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	go_eat(t_philo *philo)
{
	struct timeval current_time;

	// 1. left fork lock
	pthread_mutex_lock(philo->left);
	// 2. right fork lock
	pthread_mutex_lock(philo->right);

	// 3. print & eat time
	// 3-1. print
	printf("%s%d's philosopher is eating...\033[0m\n", "\033[32m", philo->index);
	// 3-2. eat time
	gettimeofday(&current_time, NULL);
	philo->last_eat = current_time.tv_usec;		// 먹기 시작한 시간 저장
	while (current_time.tv_usec - philo->last_eat >= philo->info->eat_time)		// 요구한 식사시간 지났는지 확인
	{
		usleep(20);		// 무한루프로 인한 성능 저하 막기 위함 (spin lock의 단점)
		gettimeofday(&current_time, NULL);		// 현재 시간 기록
	}

	// 4. left fork unlock
	pthread_mutex_unlock(philo->left);
	// 5. right fork unlock
	pthread_mutex_unlock(philo->right);
}

void	go_sleep(t_philo *philo)
{
	struct timeval	current_time;

	// print & sleep time
	printf("%s%d's philosopher is sleeping...\033[0m\n", "\033[33m", philo->index);
	gettimeofday(&current_time, NULL);
	philo->last_sleep = current_time.tv_usec;		// 자기 시작한 시간 저장
	while (current_time.tv_usec - philo->last_sleep >= philo->info->sleep_time)
	{
		usleep(20);
		gettimeofday(&current_time, NULL);		// 현재 시간 기록
	}
	printf("%s%d's philosopher is thinking...\033[0m\n", "\033[35m", philo->index);
}

