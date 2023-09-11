/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:00:18 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/11 13:03:03 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*info(void);
int		check_input(char **argv);

t_info	*info(void)
{
	static t_info	_info;

	return (&_info);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '+')
			j++;
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
	long	i;

	if ((argc > 4 && argc < 7) && check_input(argv))
	{
		(info()->n_philos) = ft_atoi(argv[1]);
		(info()->death_time) = ft_atoi(argv[2]) * 1000;
		(info()->eat_time) = ft_atoi(argv[3]) * 1000;
		(info()->sleep_time) = ft_atoi(argv[4]) * 1000;
		(info()->times_to_eat) = -1;
		if (argc == 6)
			(info()->times_to_eat) = ft_atoi(argv[5]);
		if (info()->eat_time > info()->death_time)
			(info()->eat_time) = info()->death_time;
		i = info()->eat_time - info()->sleep_time;
		if (i < 0)
			i = 0;
		(info()->think_time) = i;
		(info()->start_time) = current_time() + (info()->n_philos * 100000);
		(info()->dead) = 0;
		create_philos();
		ft_watcher();
		ft_clean();
	}
	else
		return (printf("Invalid arguments!\n"));
}
