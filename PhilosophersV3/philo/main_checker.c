/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:58:19 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/24 22:58:19 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eats(t_list *d)
{
	int	i;
	int	j;

	if (!d || !d->philo)
		return (1);

	i = 0;
	j = 0;
	if (!d->philo_eats)
		return (0);
	while (i < d->num_philos)
	{
		if (d->philo[i].num_eats >= d->philo_eats)
			j++;
		else
			break;
		i++;
	}
	if (j == d->num_philos)
	{
		d->stat = 2;
		return (1);
	}
	return (0);
}

void	main_checker(t_list *d)
{
	int		c;
	long	t;

	if (!d || !d->philo)
		return;

	c = -1;
	while (d->stat == 0)
	{
		while (++c < d->num_philos)
		{
			t = calc_time() - d->s_time;
			if (t - d->philo[c].last_eat > d->time_die || check_eats(d) == 1)
			{
				if (d->stat == 2)
					break;
				d->stat = 1;
				printer(t, c + 1, "died");
				break;
			}
		}
		if (d->stat != 0)
			break;
		c = -1;
	}
}
