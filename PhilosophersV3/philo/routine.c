/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:45:41 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/26 18:45:41 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_philo(t_list *d)
{
	int		c;
	long	time;

	if (!d || !d->philo)
		return (1);

	c = -1;
	while (++c < d->num_philos)
	{
		time = calc_time() - d->s_time;
		if (time - d->philo[c].last_eat > d->time_die)
		{
			if (d->stat == 0)
			{
				d->stat = 1;
				printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, c + 1);
			}
			return (1);
		}
	}
	return (0);
}

int	routine(t_list *d)
{
	int	i;

	if (!d || !d->philo || !d->mutex)
		return (-1);

	if (pthread_mutex_lock(&d->mutex_i) != 0)
		return (-1);
	i = d->id - 1;
	d->id++;
	if (pthread_mutex_unlock(&d->mutex_i) != 0)
		return (-1);

	if (i % 2 == 0)
		ft_usleep(d->time_eat / 2);

	while (d->stat == 0 && death_philo(d) == 0)
	{
		if (pthread_mutex_lock(&d->mutex_fork) != 0)
			return (-1);
		ft_take_fork(d, i);
		if (pthread_mutex_unlock(&d->mutex_fork) != 0)
			return (-1);

		ft_eat(d, i);
		ft_sleep(d, i);

		if (d->num_philos % 2 != 0)
			ft_usleep(d->time_sleep / 3);
	}
	return (0);
}

void	*philo_routine(void *f)
{
	t_list	*d;

	d = (t_list *)f;
	if (!d)
		return (NULL);

	while (d->init_philo == 0)
		usleep(10);

	if (routine(d) == -1)
		return (NULL);
	return (NULL);
}
