/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:18 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/04 18:07:34 by hannkim          ###   ########.fr       */
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
} t_info;

typedef struct s_philo
{
	int	eat_cnt;
	int	die_cnt;
	int	sleep_cnt;
	int	index;

//	t_info	*info;

}	t_philo;

t_philo	*parsing(char **argv, t_info *info);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *s);
int		generate_philo(t_philo *philo, t_info *info);
void	all_free(t_philo *philo, t_info *info);
void	monitoring_thread();

#endif

