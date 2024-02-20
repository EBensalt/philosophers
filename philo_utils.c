/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:37:27 by ebensalt          #+#    #+#             */
/*   Updated: 2022/08/14 03:37:27 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	my_time(void)
{
	struct timeval	time;
	long int		i;

	gettimeofday(&time, NULL);
	i = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (i);
}

void	my_msleep(int ms)
{
	long int	i;
	long int	j;

	i = my_time();
	j = 0;
	while ((j - i) < ms)
	{
		usleep(500);
		j = my_time();
	}
}
