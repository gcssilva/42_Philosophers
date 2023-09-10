/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:10:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/09/10 18:42:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define FORK "has taken a fork."
# define EAT "is eating."
# define THINK "is thinking"
# define SLEEP "is sleeping."
# define DEAD "died."

typedef struct s_philo
{
	int			id;
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

t_info	*info(void);
int		check_input(char **argv);

int		is_nb(int c);
long	ft_atoi(const char *str);
void	print_act(int time, int id, char *act);
long	current_time(void);
void	wait_time(void);

void	create_philos(void);
void	one_philo(void);
void	*philo_handler(void *ptr);
void	ft_clean(void);
void	ft_watcher(void);

int		death_check(int id);
int		philo_eat(int id);
int		philo_sleep(int id);
int		philo_think(int id);

#endif
