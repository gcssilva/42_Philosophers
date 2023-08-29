/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:10:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/08/29 16:08:37 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			n_philos;
	int			meals_left;
	int			think;
	long		last_meal;
	pthread_t	thread;
}				t_philo;


typedef struct s_info
{
	int				dead;
	int				n_philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				times_to_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	info;
	pthread_mutex_t	print_act;
}					t_info;

t_info		*info(void);

#endif
