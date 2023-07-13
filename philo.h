/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:10:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/07/12 13:59:27 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int	philos;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	times_to_eat;
}		t_info;

long	ft_atoi(char *str);

#endif
