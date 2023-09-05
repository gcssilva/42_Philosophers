/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:34:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/05 13:11:16 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(int id);
int	philo_eat(int id, int next);
int	philo_sleep(int id);
int	philo_think(int id);

int	death_check(int id)
{
	if (info()->dead > 0 || (info()->philos[id - 1].meals_left) == 0)
		return (1);
	else if ((current_time() - info()->philos[id - 1].last_meal) / 1000 > info()->death_time)
	{
		pthread_mutex_lock(&info()->info);
		(info()->dead) = 1;
		pthread_mutex_unlock(&info()->info);
		pthread_mutex_lock(&info()->print_act);
		print_act((current_time() - info()->start_time) / 1000, id, "dead");
		pthread_mutex_unlock(&info()->print_act);
		return (1);
	}
	return (0);
}

int	philo_eat(int id, int next)
{
	pthread_mutex_lock(&info()->forks[id - 1]);
	pthread_mutex_lock(&info()->forks[next - 1]);
	(info()->philos[id - 1].last_meal) = current_time();
	print_act((current_time() - info()->start_time) / 1000, id, "eating");
	usleep(info()->eat_time);
	pthread_mutex_unlock(&info()->forks[id - 1]);
	pthread_mutex_unlock(&info()->forks[next - 1]);
	info()->philos[id - 1].meals_left -= 1;
	if (info()->philos[id - 1].meals_left == 0)
		return (0);
	if (death_check(id))
		return (0);
	return (1);
}

int	philo_sleep(int id)
{
	print_act((current_time() - info()->start_time) / 1000, id, "sleeping");
	usleep(info()->sleep_time);
	if (death_check(id))
		return (0);
	return (1);
}

int	philo_think(int id)
{
	print_act((current_time() - info()->start_time) / 1000, id, "thinking");
	usleep(info()->think_time);
	if (death_check(id))
		return (0);
	return (1);
}
