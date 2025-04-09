/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:15:07 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 17:15:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_destroy(&d->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&d->print_lock);
	free(d->forks);
	free(d->philos);
}
