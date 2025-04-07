/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:11 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 17:08:11 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*check_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->list->num_philos == 1)
	{
		handle_one_philo(philo);
		return (NULL);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_one(philo);
	waiting_turn(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->list->check_death);
		if (philo->list->stop == 1)
		{
			pthread_mutex_unlock(&philo->list->check_death);
			break ;
		}
		pthread_mutex_unlock(&philo->list->check_death);
		usleep(100);
		eat(philo);
		if (eat_enough(philo))
			return (NULL);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor_philos(void *arg)
{
	t_list	*d;

	d = (t_list *)arg;
	while (!d->stop)
	{
		check_death(d);
		pthread_mutex_lock(&d->check_death);
		if (d->stop == 1)
		{
			pthread_mutex_unlock(&d->check_death);
			return (NULL);
		}
		pthread_mutex_unlock(&d->check_death);
		check_all_eaten(d);
		usleep(100);
	}
	return (NULL);
}
