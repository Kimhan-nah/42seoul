/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:18 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 12:59:15 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#define SUCCESS 0
#define FAILURE 1

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct s_info
{
	int philo_number;
	int die_time;
	int	eat_time;
	int sleep_time;
	int	must_eat;
	int	alive;		// for die
} t_info;

typedef struct s_philo
{
	int	index;
	int	eat_cnt;
	int	die_cnt;
	int	sleep_cnt;
	t_info	*info;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;


t_philo	*parsing(int argc, char **argv);
void	*exit_free(t_philo *philo);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *s);
int		born_philo(t_philo *philo, t_info *info);
void	monitoring_thread();

#endif

