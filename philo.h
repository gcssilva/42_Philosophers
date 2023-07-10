/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:10:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/07/10 14:14:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int	philos;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	times_to_eat;
}		t_philo;


#endif
