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
	while (d->stat == 0)
	{
		if (pthread_mutex_lock(&d->mutex_fork) != 0)
			return (-1);
		if (d->stat != 0)
		{
			pthread_mutex_unlock(&d->mutex_fork);
			break ;
		}
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
