/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:48:47 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/12 16:38:03 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(void);
void	*one_philo(void);
void	*philo_handler(void *ptr);
void	ft_clean(void);
void	ft_watcher(void);

void	create_philos(void)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = info()->n_philos;
	(info()->philos) = (t_philo *)malloc(n_philos * (sizeof(t_philo)));
	(info()->forks) = (pthread_mutex_t *)malloc(n_philos
			* (sizeof(pthread_mutex_t)));
	while (++i < n_philos)
		pthread_mutex_init(&info()->forks[i], 0);
	i = -1;
	while (++i < n_philos)
	{
		(info()->philos[i].id) = i + 1;
		(info()->philos[i].meals_left) = info()->times_to_eat;
		(info()->philos[i].last_meal) = info()->start_time;
	}
	(info()->times_to_eat) = (info()->n_philos);
	pthread_mutex_init(&info()->print_act, 0);
	pthread_mutex_init(&info()->info, 0);
	i = -1;
	while (++i < n_philos)
		pthread_create(&(info()->philos[i].thread), 0,
			&philo_handler, (void *)&(info()->philos[i]));
}

void	*one_philo(void)
{
	print_act((current_time() - info()->start_time) / 1000, 1, THINK);
	usleep(info()->death_time);
	info()->dead = 1;
	print_act((info()->death_time) / 1000, 1, DEAD);
	return (0);
}

void	*philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	wait_time();
	if (info()->n_philos == 1)
		return (one_philo());
	else if (philo->id % 2 == 1)
	{
		print_act((current_time() - info()->start_time) / 1000,
			philo->id, THINK);
		usleep(info()->eat_time);
	}
	while (death_check(philo->id))
	{
		if (!philo_eat(philo->id) || !philo_sleep(philo->id)
			|| !philo_think(philo->id))
			return (0);
	}
	return (0);
}

void	ft_clean(void)
{
	int	i;

	i = -1;
	while (++i < info()->n_philos)
		pthread_mutex_destroy(&info()->forks[i]);
	pthread_mutex_destroy(&info()->print_act);
	pthread_mutex_destroy(&info()->info);
	free(info()->philos);
	free(info()->forks);
}

void	ft_watcher(void)
{
	int	i;

	i = -1;
	while (++i < info()->n_philos)
		pthread_join(info()->philos[i].thread, 0);
}
