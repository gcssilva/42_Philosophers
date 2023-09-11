/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:34:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/11 17:06:37 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		death_check(int id);
int		philo_eat(int id);
int		philo_sleep(int id);
int		philo_think(int id);
void	lock_forks(int id);

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
		(info()->dead) = 1;
		pthread_mutex_lock(&info()->print_act);
		print_act((current_time() - info()->start_time) / 1000, id, DEAD);
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
	lock_forks(id);
	(info()->philos[id - 1].last_meal) = current_time();
	pthread_mutex_lock(&info()->info);
	pthread_mutex_lock(&info()->print_act);
	if (verify_end())
		return (0);
	print_act((current_time() - info()->start_time) / 1000, id, EAT);
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
	pthread_mutex_lock(&info()->info);
	pthread_mutex_lock(&info()->print_act);
	if (verify_end())
		return (0);
	print_act((current_time() - info()->start_time) / 1000, id, SLEEP);
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
			- info()->philos[id - 1].last_meal);
	pthread_mutex_lock(&info()->info);
	pthread_mutex_lock(&info()->print_act);
	if (verify_end())
		return (0);
	print_act((current_time() - info()->start_time) / 1000, id, THINK);
	if (i < info()->think_time)
		usleep(i);
	else
		usleep(info()->think_time);
	return (death_check(id));
}

void	lock_forks(int id)
{
	int	fork_1;
	int	fork_2;

	if (id == info()->n_philos)
	{
		fork_1 = 0;
		fork_2 = id - 1;
	}
	else if (id % 2 == 1)
	{
		fork_1 = id - 1;
		fork_2 = id;
	}
	else
	{
		fork_1 = id;
		fork_2 = id - 1;
	}
	pthread_mutex_lock(&info()->forks[fork_1]);
	pthread_mutex_lock(&info()->print_act);
	print_act((current_time() - info()->start_time) / 1000, id, FORK);
	pthread_mutex_lock(&info()->forks[fork_2]);
	pthread_mutex_lock(&info()->print_act);
	print_act((current_time() - info()->start_time) / 1000, id, FORK);
}
