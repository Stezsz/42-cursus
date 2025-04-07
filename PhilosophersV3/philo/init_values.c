/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:01 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 12:28:33 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_list *d)
{
	if (pthread_mutex_init(&d->mutex_i, NULL) != 0
		|| pthread_mutex_init(&d->mutex_msg, NULL) != 0
		|| pthread_mutex_init(&d->mutex_fork, NULL) != 0)
		return (-1);
	return (0);
}

static int	allocate_resources(t_list *d)
{
	d->thread = malloc(sizeof(pthread_t) * d->num_philos);
	if (!d->thread)
		return (-1);
	d->philo = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->philo)
		return (free(d->thread), -1);
	d->mutex = malloc(sizeof(pthread_mutex_t) * d->num_philos);
	if (!d->mutex)
		return (free(d->thread), free(d->philo), -1);
	return (0);
}

static void	init_philosophers(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		d->philo[i].num_eats = 0;
		d->philo[i].fork_r = (i - 1 + d->num_philos) % d->num_philos;
		d->philo[i].fork_l = i;
		i++;
	}
}

int	init_values(t_list *d)
{
	d->init_philo = 0;
	if (allocate_resources(d) != 0)
		return (-1);
	if (init_mutexes(d) != 0)
		return (free(d->thread), free(d->philo), -1);
	init_philosophers(d);
	return (0);
}
