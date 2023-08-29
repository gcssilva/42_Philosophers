/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:48:47 by gsilva            #+#    #+#             */
/*   Updated: 2023/08/29 16:08:51 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(int i)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = info()->n_philos;
	(info()->philos) = (t_philo *)malloc(n_philos * (sizeof(t_philo)));
	(info()->forks) = (pthread_mutex_t *)malloc(n_philos * (sizeof(pthread_mutex_t)));
	while (++i < n_philos)
	{
		(info()->philos[i].id) = i + 1;
		(info()->philos[i].n_philos) = n_philos;
		(info()->philos[i].meals_left) = info()->times_to_eat;
		(info()->philos[i].last_meal) = 0;
		(info()->philos[i].think) = i;
		pthread_create((info()->philos[i].thread), 0, philo_handler, &(info()->philos[i]));
	}
	i = -1;
	while (++i < n_philos)
		pthread_mutex_init(&info()->forks[i], 0);
}

void	philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if(philo->n_philos == 1)
	{
		print_act(get, 1, "dead");
		usleep(info()->death_time)
		print_act(info()->death_time, 1, "dead");
	}
}