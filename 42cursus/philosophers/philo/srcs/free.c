/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:01:14 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/11 18:04:19 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	free_thread(pthread_t *tid, int tid_index)
{
	int	i;

	i = 0;
	while (tid && i < tid_index)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	if (tid)
		free(tid);
}

static void	free_info(t_info *info)
{
	if (info->mutex)
	{
		pthread_mutex_destroy(info->mutex);
		free(info->mutex);
	}
	if (info->is_finish)
		free(info->is_finish);
	free(info);
}

void	free_resources(pthread_t *tid, t_philo *philos, t_info *info,
	int tid_index)
{
	int	i;

	i = 0;
	if (tid)
		free_thread(tid, tid_index);
	while (philos + i && (i < info->philo_number))
	{
		if (philos[i].left)
		{
			pthread_mutex_destroy(philos[i].left);
			free(philos[i].left);
		}
		i++;
	}
	if (info)
		free_info(info);
	if (philos)
		free(philos);
}
