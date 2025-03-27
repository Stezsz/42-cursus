/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:01 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/27 16:53:20 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_values(t_list *d)
{
	int	i;

	d->init_philo = 0;
	d->thread = malloc(sizeof(pthread_t) * d->num_philos);
	if (!d->thread)
		return (-1);

	if (pthread_mutex_init(&d->mutex_i, NULL) != 0 ||
		pthread_mutex_init(&d->mutex_msg, NULL) != 0 ||
		pthread_mutex_init(&d->mutex_fork, NULL) != 0)
	{
		free(d->thread);
		return (-1);
	}

	d->philo = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->philo)
	{
		pthread_mutex_destroy(&d->mutex_i);
		pthread_mutex_destroy(&d->mutex_msg);
		pthread_mutex_destroy(&d->mutex_fork);
		free(d->thread);
		return (-1);
	}

	d->mutex = malloc(sizeof(pthread_mutex_t) * d->num_philos);
	if (!d->mutex)
	{
		pthread_mutex_destroy(&d->mutex_i);
		pthread_mutex_destroy(&d->mutex_msg);
		pthread_mutex_destroy(&d->mutex_fork);
		free(d->thread);
		free(d->philo);
		return (-1);
	}

	i = 0;
	while (i < d->num_philos)
	{
		d->philo[i].num_eats = 0;
		d->philo[i].fork_r = (i - 1 + d->num_philos) % d->num_philos;
		d->philo[i].fork_l = i;
		i++;
	}
	return (0);
}
