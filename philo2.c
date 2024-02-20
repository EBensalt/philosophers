/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:39:22 by ebensalt          #+#    #+#             */
/*   Updated: 2022/08/14 04:28:10 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine2(t_arg *data, int id)
{
	pthread_mutex_lock(&data->philo.race_print);
	printf("%s%ldms%s philo %d is sleeping\n",
		Y, (my_time() - data->t), W, id);
	pthread_mutex_unlock(&data->philo.race_print);
	my_msleep(data->time_to_sleep);
	pthread_mutex_lock(&data->philo.race_print);
	printf("%s%ldms%s philo %d is thinking\n",
		Y, (my_time() - data->t), W, id);
	pthread_mutex_unlock(&data->philo.race_print);
}

void	routine3(t_arg *data, int id)
{
	pthread_mutex_lock(&data->philo.fork[id - 1]);
	pthread_mutex_lock(&data->philo.race_print);
	printf("%s%ldms%s philo %d%s has taken a fork 1%s\n",
		Y, (my_time() - data->t), W, id, B, W);
	pthread_mutex_unlock(&data->philo.race_print);
	pthread_mutex_lock(&data->philo.fork[id % data->nu_philo]);
	pthread_mutex_lock(&data->philo.race_print);
	printf("%s%ldms%s philo %d%s has taken a fork 2%s\n",
		Y, (my_time() - data->t), W, id, B, W);
	pthread_mutex_unlock(&data->philo.race_print);
	pthread_mutex_lock(&data->philo.race_print);
	printf("%s%ldms%s philo %d%s is eating%s\n",
		Y, (my_time() - data->t), W, id, G, W);
	pthread_mutex_unlock(&data->philo.race_print);
	pthread_mutex_lock(&data->philo.races_2);
	data->last_meal[id - 1] = my_time();
	pthread_mutex_unlock(&data->philo.races_2);
	my_msleep(data->time_to_eat);
	pthread_mutex_lock(&data->philo.races_3);
	if (data->nu_of_times_to_eat[id - 1] != 0)
		data->nu_of_times_to_eat[id - 1]--;
	pthread_mutex_unlock(&data->philo.races_3);
	pthread_mutex_unlock(&data->philo.fork[id - 1]);
	pthread_mutex_unlock(&data->philo.fork[id % data->nu_philo]);
}

void	*routine(void *arg)
{
	t_arg		*data;
	int			id;

	data = (t_arg *)arg;
	pthread_mutex_lock(&data->philo.races_1);
	id = data->id;
	pthread_mutex_unlock(&data->philo.races_1);
	if (id == 1)
	{
		pthread_mutex_lock(&data->philo.races_4);
		data->t = my_time();
		pthread_mutex_unlock(&data->philo.races_4);
	}
	while (1337)
	{
		routine3(data, id);
		if (data->nu_of_times_to_eat[id - 1] == 0)
			return (NULL);
		routine2(data, id);
	}
	return (0);
}
