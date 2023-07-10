/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:00:18 by gsilva            #+#    #+#             */
/*   Updated: 2023/07/10 15:03:56 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo(void)
{
	static t_philo	_philo;

	return (&_philo);
}

int	is_nb(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_nb(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if ((argc > 4 && argc < 7) && check_input(argv))
	{
		(philo()->philos) = ft_atoi(argv[1]);
		(philo()->death_time) = ft_atoi(argv[2]);
		(philo()->eat_time) = ft_atoi(argv[3]);
		(philo()->sleep_time) = ft_atoi(argv[4]);
		if (argc == 6)
			(philo()->times_to_eat) = ft_atoi(argv[5]);
	}
	else
		return(write(1, "Invalid arguments!\n", 19));
}
