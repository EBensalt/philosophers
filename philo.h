/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:56:34 by ebensalt          #+#    #+#             */
/*   Updated: 2022/08/14 04:28:40 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# define Y "\033[1;33m"
# define W "\033[0m"
# define B "\033[1;36m"
# define G "\033[1;32m"
# define R "\033[1;31m"

struct	s_arg;

typedef struct s_philo
{
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	race_print;
	pthread_mutex_t	races_1;
	pthread_mutex_t	races_2;
	pthread_mutex_t	races_3;
	pthread_mutex_t	races_4;
	struct s_arg	*arg;
}	t_philo;

typedef struct s_arg
{
	int			nu_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			*nu_of_times_to_eat;
	t_philo		philo;
	int			id_flag;
	int			id;
	long int	*last_meal;
	long int	t;
	int			i;
}	t_arg;

int			my_atoi(const char *str);
long int	my_time(void);
void		my_msleep(int ms);
void		*routine(void *arg);
int			ft_death(t_arg *data);
#endif