/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:36 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 17:55:56 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitoring_thread()
{
}

void	*start(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	 

	// 뭘 리턴해야 함?
	return NULL;
}

int	generate_philo(t_philo *philo, t_info *info)
{
	int i;
	pthread_t	*tid;

	i = 0;
	tid = (pthread_t *)ft_calloc(info->philo_number, sizeof(pthread_t));
	if (!tid)
		return (FAILURE);
	while (i < info->philo_number)
	{
		pthread_create(&tid[i], NULL, start, &philo[i]);
		i++;
	}
	return (SUCCESS);
}
