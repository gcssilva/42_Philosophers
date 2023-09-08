/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:00:18 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/08 14:07:30 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*info(void);
int	check_input(char **argv);

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
		i = info()->eat_time - info()->sleep_time;
		if (i < 0)
			i = 0;
		(info()->think_time) = i * 1000;
		(info()->start_time) = current_time() + 100000;
		(info()->dead) = 0;
		pthread_mutex_init(&info()->print_act, 0);
		pthread_mutex_init(&info()->info, 0);
		create_philos();
		ft_watcher();
		ft_clean();
	}
	else
		return(printf("Invalid arguments!\n"));
}
