/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:24 by ebensalt          #+#    #+#             */
/*   Updated: 2022/07/30 20:10:06 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f1(const char *str, int a, unsigned long c, int b)
{
	if (str[a] >= 48 && str[a] <= 57)
	{
		while (str[a] >= 48 && str[a] <= 57)
		{
			c = c * 10 + (str[a] - '0');
			a++;
		}
		if (c > 9223372036854775807 && b == 1)
			return (-1);
		if (c - 1 > 9223372036854775807 && b == -1)
			return (0);
		return (c * b);
	}
	return (0);
}

int	M_atoi(const char *str)
{
	int				a;
	int				b;
	unsigned long	c;

	a = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	b = 1;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			b = b * -1;
		a++;
	}
	c = 0;
	a = f1(str, a, c, b);
	return (a);
}
