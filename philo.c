/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:55:45 by ebensalt          #+#    #+#             */
/*   Updated: 2022/08/14 04:28:35 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*ft_arg(int ac, char **av)
{
	t_arg	*data;
	int		i;

	data = malloc(sizeof(t_arg));
	i = -1;
	data->nu_philo = my_atoi(av[1]);
	data->time_to_die = my_atoi(av[2]);
	data->time_to_eat = my_atoi(av[3]);
	data->time_to_sleep = my_atoi(av[4]);
	data->nu_of_times_to_eat = malloc(data->nu_philo * sizeof(int));
	if (ac == 6)
	{
		while (++i < data->nu_philo)
		{
			data->nu_of_times_to_eat[i] = my_atoi(av[5]);
		}
	}
	else
	{
		while (++i < data->nu_philo)
			data->nu_of_times_to_eat[i] = -1;
	}
	return (data);
}

void	philosophers(t_arg *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	data->philo.philo = malloc(data->nu_philo * sizeof(pthread_t));
	data->philo.fork = malloc(data->nu_philo * sizeof(pthread_mutex_t));
	data->last_meal = malloc(data->nu_philo * sizeof(long int));
	pthread_mutex_init(&data->philo.race_print, NULL);
	pthread_mutex_init(&data->philo.races_1, NULL);
	pthread_mutex_init(&data->philo.races_2, NULL);
	pthread_mutex_init(&data->philo.races_3, NULL);
	pthread_mutex_init(&data->philo.races_4, NULL);
	while (++i < data->nu_philo)
		pthread_mutex_init(&data->philo.fork[i], NULL);
	i = -1;
	while (++i < data->nu_philo)
	{
		pthread_mutex_lock(&data->philo.races_1);
		data->id = i + 1;
		pthread_mutex_unlock(&data->philo.races_1);
		data->last_meal[i] = 0;
		pthread_create(&data->philo.philo[i], NULL, routine, (void *)data);
		usleep(100);
	}
}

int	ft_check_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == 43)
			j++;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	*data;

	if (ac != 5 && ac != 6)
	{
		write(2, "wrong number of arguments!\n", 27);
		return (1);
	}
	if (ft_check_input(ac, av) == 1)
	{
		write(2, "wrong input!\n", 13);
		return (2);
	}
	data = ft_arg(ac, av);
	philosophers(data);
	while (1337)
	{
		if (ft_death(data) == 1)
		{
			free((void *)data);
			return (0);
		}
		usleep(500);
	}
	return (0);
}
