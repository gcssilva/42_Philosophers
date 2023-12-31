/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:33:27 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/15 18:19:07 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_nb(int c);
long	ft_atoi(const char *str);
void	print_act(int id, char *act);
long	current_time(void);
void	wait_time(void);

int	is_nb(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long int	s;
	long int	nbr;

	s = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -s;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr = nbr * 10 + (*str++ - 48);
		if (nbr > 2147483648)
		{
			if (s > 0)
				return (-1);
			return (0);
		}
	}
	return (nbr * s);
}

void	print_act(int id, char *act)
{
	pthread_mutex_lock(&info()->print_act);
	if (!death_check(id, 1))
	{
		pthread_mutex_unlock(&info()->print_act);
		return ;
	}
	printf("%ld\t%i\t%s\n", (current_time() - info()->start_time)
		/ 1000, id, act);
	pthread_mutex_unlock(&info()->print_act);
}

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000000L) + tv.tv_usec);
}

void	wait_time(void)
{
	long	time;

	time = (info()->start_time - current_time());
	if (time > 0)
		usleep(time);
}
