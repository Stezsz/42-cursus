/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:02:57 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 17:02:57 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_lock(&d->check_meal);
		if (get_time() - d->philos[i].last_meal_time >= d->time_to_die)
		{
			pthread_mutex_unlock(&d->check_meal);
			ft_print(d, d->philos[i].id, "died");
			pthread_mutex_lock(&d->check_death);
			d->stop = 1;
			pthread_mutex_unlock(&d->check_death);
			return ;
		}
		pthread_mutex_unlock(&d->check_meal);
		i++;
	}
}

void	check_all_eaten(t_list *d)
{
	int	i;
	int	eaten_count;

	i = 0;
	eaten_count = 0;
	while (i < d->num_philos)
	{
		if (eat_enough(&d->philos[i]))
			eaten_count++;
		i++;
	}
	if (eaten_count == d->num_philos)
		d->stop = 2;
}
