/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:48:47 by gsilva            #+#    #+#             */
/*   Updated: 2023/08/31 16:45:36 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(void);
void	*philo_handler(void *ptr);

void	create_philos(void)
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
		(info()->philos[i].next) = i + 2;
		if (i + 2 > n_philos)
			(info()->philos[i].next) = 1;
		(info()->philos[i].meals_left) = info()->times_to_eat;
		(info()->philos[i].last_meal) = info()->start_time;
		pthread_create(&(info()->philos[i].thread), 0, &philo_handler, (void *)&(info()->philos[i]));
	}
	i = -1;
	while (++i < n_philos)
		pthread_mutex_init(&info()->forks[i], 0);
}

void	*philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	wait_time(info()->start_time);
	if(philo->id == philo->next)
	{
		print_act((current_time() - info()->start_time) / 1000, 1, "thinking");
		usleep(info()->death_time);
		print_act((info()->death_time) / 1000, 1, "dead");
		return (0);
	}
	while (!death_check(philo->id))
	{
		if (!philo_eat(philo->id, philo->next))
			return (0);
		if (!philo_sleep(philo->id))
			return (0);
		if (!philo_think(philo->id))
			return (0);
	}
	return (0);
}
