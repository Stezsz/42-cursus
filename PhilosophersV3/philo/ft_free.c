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
		return ;
	if (d->mutex)
	{
		i = 0;
		while (i < d->num_philos)
			pthread_mutex_destroy(&d->mutex[i++]);
	}
	pthread_mutex_destroy(&d->mutex_i);
	pthread_mutex_destroy(&d->mutex_msg);
	pthread_mutex_destroy(&d->mutex_fork);
	pthread_mutex_destroy(&d->mutex_last_eat);
	pthread_mutex_destroy(&d->mutex_stat);
	if (d->thread)
	{
		i = 0;
		while (i < d->num_philos)
			pthread_join(d->thread[i++], NULL);
		free(d->thread);
	}
	free(d->philo);
	free(d->mutex);
	free(d);
}
