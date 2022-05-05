/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:18 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/05 17:42:39 by hannkim          ###   ########.fr       */
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
#include <sys/time.h>

typedef enum s_state
{
	eating = 0,
	sleeping,
	thinking,
	dead,
}	t_state;

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
	int				index;
	int				last_eat;
//	int				die_cnt;
	int				last_sleep;

	t_state			state;
	t_info			*info;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;


t_philo	*parsing(int argc, char **argv);
void	*exit_free(t_philo *philos);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *s);
int		generate_philo(t_philo *philos, t_info *info);
void	monitoring_thread(t_philo *philos);
void	go_eat(t_philo *philo);
void	go_sleep(t_philo *philo);

#endif

