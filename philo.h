/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:10:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/08/31 16:42:11 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			next;
	int			meals_left;
	long		last_meal;
	pthread_t	thread;
}				t_philo;


typedef struct s_info
{
	int				dead;
	int				n_philos;
	int				times_to_eat;
	long			eat_time;
	long			sleep_time;
	long			think_time;
	long			death_time;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	info;
	pthread_mutex_t	print_act;
}					t_info;

t_info		*info(void);
int			check_input(char **argv);

int		is_nb(int c);
long	ft_atoi(const char *str);
void	print_act(int time, int id, char *act);
long	current_time(void);
void	wait_time(long start);

void	create_philos(void);
void	*philo_handler(void *ptr);

int	death_check(int id);
int	philo_eat(int id, int next);
int	philo_sleep(int id);
int	philo_think(int id);

#endif
