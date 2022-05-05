/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:34 by hannkim           #+#    #+#             */
/*   Updated: 2022/05/06 04:29:36 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_philo		*philos;

	if (argc != 5 && argc != 6)
		return (FAILURE);
	//숫자인지 숫자라면 양의 정수인지 체크 하셔야합니다
	philos = parsing(argc, argv);
	if (!philos)
		return (FAILURE);
	if (generate_philo(philos, philos->info) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}
