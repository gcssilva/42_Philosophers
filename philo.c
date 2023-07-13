/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:00:18 by gsilva            #+#    #+#             */
/*   Updated: 2023/07/12 14:16:41 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*info(void)
{
	static t_info	_info;

	return (&_info);
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

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] == '+')
				j++;
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
		(info()->philos) = ft_atoi(argv[1]);
		(info()->death_time) = ft_atoi(argv[2]);
		(info()->eat_time) = ft_atoi(argv[3]);
		(info()->sleep_time) = ft_atoi(argv[4]);
		if (argc == 6)
			(info()->times_to_eat) = ft_atoi(argv[5]);
	}
	else
		return(write(1, "Invalid arguments!\n", 19));
	return (0);
}
