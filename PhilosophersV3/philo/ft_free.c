/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:38:40 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/27 17:24:46 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_list *d)
{
	int	i;

	if (!d)
		return;

	// Primeiro destruímos todos os mutexes
	if (d->mutex)
	{
		i = 0;
		while (i < d->num_philos)
		{
			pthread_mutex_destroy(&d->mutex[i]);
			i++;
		}
	}

	// Destruímos os mutexes individuais
	pthread_mutex_destroy(&d->mutex_i);
	pthread_mutex_destroy(&d->mutex_msg);
	pthread_mutex_destroy(&d->mutex_fork);
	pthread_mutex_destroy(&d->mutex_last_eat);
	pthread_mutex_destroy(&d->mutex_stat);

	// Depois liberamos a memória
	if (d->thread)
	{
		i = 0;
		while (i < d->num_philos)
		{
			pthread_join(d->thread[i], NULL);
			i++;
		}
		free(d->thread);
		d->thread = NULL;
	}
	if (d->philo)
	{
		free(d->philo);
		d->philo = NULL;
	}
	if (d->mutex)
	{
		free(d->mutex);
		d->mutex = NULL;
	}
	free(d);
}
