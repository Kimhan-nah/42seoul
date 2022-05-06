/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:36 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/06 15:35:26 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 * 모든 스레드가 살아있는 지 확인하고 죽은 스레드가 있으면 종료시켜야 함
 */
void	monitoring_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (stopwatch_ms(philos[i].last_eat) <= philos->info->die_time)
	{
		i = (i + 1) % philos->info->philo_number;
		usleep(10);			// for 성능
	}
	pthread_mutex_lock(philos->info->print);
	philos->info->alive = 1;
	printf("%s%lldms %d died \033[0m\n", "\033[031m", stopwatch_ms(philos->info->start_time), philos[i].index);
	pthread_mutex_unlock(philos->info->print);
}

/*
 * 스레드 함수 : eat, sleep, thinkg 반복
 */
void	*born_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;		// casting
	if (philo->index % 2 == 0)		// 짝수는 기다리고, 홀수 먼저 실행
		usleep(50);
	while (!philo->info->alive)		// 살아있으면 계속 반복
	{
		go_eat(philo);
		go_sleep(philo);
	}
	return NULL;
}

/*
 * philosopher 스레드 생성
 * 철학자 eat, sleep, think하는 동안 기다렸다가 스레드 종료
 */
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
	info->start_time = get_current_ms();		// 시작 시간 저장
	
	while (i < info->philo_number)
	{
		philos[i].last_eat = info->start_time;
		pthread_create(tid + i, NULL, born_philo, philos + i);
		i++;
	}

	// 철학자 먹고 잘 동안 기다리기
	monitoring_thread(philos);

	// 종료된 철학자 스레드 기다렸다가 조인
	i = 0;
	while (i < philos->info->philo_number)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	
	// mutex_destroy -> 사용한 자원 해제
	i = 0;
	while (i < info->philo_number)
	{
		pthread_mutex_destroy(philos[i].left);
		i++;
	}
	pthread_mutex_destroy(info->print);

	// free memory
	free(tid);
	free(info);
	free(philos);

	return (SUCCESS);
}
