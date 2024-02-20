/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:41:10 by ebensalt          #+#    #+#             */
/*   Updated: 2022/08/14 04:33:56 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death2(int i, t_arg *data, long int die, int k)
{	
	while (++i < data->nu_philo)
	{
		pthread_mutex_lock(&data->philo.races_2);
		if (data->last_meal[i] <= data->time_to_die)
			data->last_meal[i] = my_time();
		if ((die - data->last_meal[i]) >= data->time_to_die)
		{
			pthread_mutex_lock(&data->philo.race_print);
			pthread_mutex_lock(&data->philo.races_3);
			while (++k < data->nu_philo)
				pthread_detach(data->philo.philo[k]);
			printf("%s%ldms philo %d has died!\n%s",
				R, (my_time() - data->t), (i + 1), W);
			return (1);
		}
		pthread_mutex_unlock(&data->philo.races_2);
	}
	return (0);
}

int	ft_death3(int i, t_arg *data, int j, int k)
{
	while (++i < data->nu_philo)
	{
		pthread_mutex_lock(&data->philo.races_3);
		if (data->nu_of_times_to_eat[i] == 0)
			j++;
		pthread_mutex_unlock(&data->philo.races_3);
	}
	if (j == data->nu_philo)
	{
		pthread_mutex_lock(&data->philo.race_print);
		while (++k < data->nu_philo)
			pthread_detach(data->philo.philo[k]);
		return (1);
	}
	return (0);
}

int	ft_death(t_arg *data)
{
	long int	die;
	int			i;
	int			j;
	int			k;
	int			d;

	die = my_time();
	j = 0;
	i = -1;
	k = -1;
	d = ft_death2(i, data, die, k);
	if (d == 1)
		return (1);
	i = -1;
	d = ft_death3(i, data, j, k);
	return (d);
}
