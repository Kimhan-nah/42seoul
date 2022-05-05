/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:36 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 18:50:38 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 * 모든 스레드가 살아있는 지 확인하고 죽은 스레드가 있으면 종료시켜야 함
 */
void	monitoring_thread(t_philo *philos)
{
	struct timeval	current_time;
	int	die_time;
	int	i;

	i = 0;
	die_time = philos->info->die_time;
	gettimeofday(&current_time, NULL);
	while (current_time.tv_usec - philos[i].last_eat >= die_time)			// 살아있는 동안 계속 감시
	{
		i++;
		usleep(10);			// ?? 필요한지?? 그냥 무한루프 돌아도 되는지? 
	}

	// 죽은 스레드 발견하면 루프 빠져나오고, 자원 해제하고 프로그램 종료해야 함
	philos->info->alive = 1;	// 죽음
	printf("%d's philosoper die\n", philos[i].index);
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
		// 굶어 죽는 경우는?? 
	}
	//	pthread_exit(NULL);
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
	while (i < info->philo_number)
	{
		pthread_create(tid + i, NULL, born_philo, philos + i);
		i++;
	}
	// 철학자 먹고 잘 동안 기다리기
	// monitoring??

	monitoring_thread(philos);
	// 종료된 철학자 스레드 기다렸다가 조인
	i = 0;
	while (i < info->philo_number)
	{
		pthread_join(tid[i], NULL);
		i++;
	}


	return (SUCCESS);
}
