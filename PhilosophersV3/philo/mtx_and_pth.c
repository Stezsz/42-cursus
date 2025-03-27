/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_and_pth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:55:07 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/24 22:55:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		if (pthread_mutex_init(&d->mutex[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&d->mutex[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	create_threads(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		if (pthread_mutex_lock(&d->mutex_last_eat) != 0)
			return (-1);
		d->philo[i].last_eat = 0;
		if (pthread_mutex_unlock(&d->mutex_last_eat) != 0)
			return (-1);

		if (pthread_create(&d->thread[i], NULL, &philo_routine, (void *)d) != 0)
		{
			while (--i >= 0)
				pthread_detach(d->thread[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}


