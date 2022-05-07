/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:18 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/06 21:24:44 by hannah           ###   ########.fr       */
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

typedef enum e_bool
{
	false = 0,
	true,
}	t_bool;

typedef	enum e_state
{
	grabbing = 0,
	eating,
	sleeping,
	thinking,
}	t_state;

typedef struct s_info
{
	int				philo_number;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;

	long long		start_time;
	int				alive;		// for die
	t_bool			*check_must_eat;
	int				count_must_eat;

	pthread_mutex_t	*print;
}	t_info;

typedef struct s_philo
{
	int				index;
	long long		last_eat;
	long long		last_sleep;
	int				count_eat;

	t_info			*info;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;


t_philo	*parsing(int argc, char **argv);
void	*exit_free(t_philo *philos);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *s);
int		generate_philo(t_philo *philos, t_info *info);
void	monitoring_thread(t_philo *philos, t_info *info);
void	go_eat(t_philo *philo);
void		go_sleep(t_philo *philo);
long long	get_current_ms();
long long	stopwatch_ms(long long timestamp);

#endif

