/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:34:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/15 17:05:55 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		death_check(int id);
int		philo_eat(int id);
int		philo_sleep(int id);
int		philo_think(int id);
void	lock_forks(int id, int fork_1, int fork_2);

int	death_check(int id)
{
	pthread_mutex_lock(&info()->info);
	if (info()->dead > 0 || (info()->times_to_eat) == 0)
	{
		pthread_mutex_unlock(&info()->info);
		return (0);
	}
	if ((current_time() - info()->philos[id - 1].last_meal)
		> info()->death_time)
	{
		printf("%ld\t%i\t%s\n", ((current_time() - info()->start_time)
				/ 1000), id, DEAD);
		(info()->dead) = 1;
		pthread_mutex_unlock(&info()->info);
		return (0);
	}
	pthread_mutex_unlock(&info()->info);
	return (1);
}

int	philo_eat(int id)
{
	int	i;

	if (id != info()->n_philos)
		i = id;
	else
		i = 0;
	lock_forks(id, id - 1, id % info()->n_philos);
	(info()->philos[id - 1].last_meal) = current_time();
	print_act(id, EAT);
	info()->philos[id - 1].meals_left -= 1;
	if (info()->philos[id - 1].meals_left == 0)
	{
		pthread_mutex_lock(&info()->info);
		info()->times_to_eat -= 1;
		pthread_mutex_unlock(&info()->info);
	}
	usleep(info()->eat_time);
	pthread_mutex_unlock(&info()->forks[id - 1]);
	pthread_mutex_unlock(&info()->forks[i]);
	return (death_check(id));
}

int	philo_sleep(int id)
{
	long	i;

	i = info()->death_time - (current_time()
			- info()->philos[id - 1].last_meal);
	print_act(id, SLEEP);
	if (i < info()->sleep_time)
		usleep(i);
	else
		usleep(info()->sleep_time);
	return (death_check(id));
}

int	philo_think(int id)
{
	long	i;

	i = info()->death_time - (current_time()
			- info()->philos[id - 1].last_meal) - (info()->eat_time);
	print_act(id, THINK);
	if (i > 0)
		usleep(i);
	return (death_check(id));
}

void	lock_forks(int id, int fork_1, int fork_2)
{
	if (id % 2 == 1 && id != info()->n_philos)
	{
		pthread_mutex_lock(&info()->forks[fork_1]);
		print_act(id, FORK);
		pthread_mutex_lock(&info()->forks[fork_2]);
		print_act(id, FORK);
	}
	else
	{
		pthread_mutex_lock(&info()->forks[fork_2]);
		print_act(id, FORK);
		pthread_mutex_lock(&info()->forks[fork_1]);
		print_act(id, FORK);
	}
}
