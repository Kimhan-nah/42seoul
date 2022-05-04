/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 17:25:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	initialize(t_philo *philo, t_info *info)
{
	int i;

	i = 0;
	while (i < info->philo_number)
	{
		philo[i].eat_cnt = info->eat_time;
		philo[i].die_cnt = info->die_time;
		philo[i].sleep_cnt = info->sleep_time;
//		philo[i].info = info;
		philo[i].index = i + 1;
		i++;
	}
}

t_philo	*parsing(char **argv, t_info *info)
{
	t_philo *philo;

	info->philo_number = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);

	philo = (t_philo *)ft_calloc(info->philo_number, sizeof(t_philo));
	if (!philo)
		return (NULL);
	initialize(philo, info);
	return (philo);
}
