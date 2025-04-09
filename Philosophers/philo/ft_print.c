/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:50:08 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:08 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_list *d, int id, char *act)
{
	pthread_mutex_lock(&d->print_lock);
	pthread_mutex_lock(&d->check_death);
	if (!d->stop)
	{
		pthread_mutex_unlock(&d->check_death);
		if (ft_strcmp(act, "died") == 0)
			printf("%ld %d %s\n", get_time() - d->start_time, id, act);
		else if (ft_strcmp(act, "has taken a fork") == 0)
			printf("%ld %d %s\n", get_time() - d->start_time, id, act);
		else if (ft_strcmp(act, "is eating") == 0)
			printf("%ld %d %s\n", get_time() - d->start_time, id, act);
		else if (ft_strcmp(act, "is sleeping") == 0)
			printf("%ld %d %s\n", get_time() - d->start_time, id, act);
		else if (ft_strcmp(act, "is thinking") == 0)
			printf("%ld %d %s\n", get_time() - d->start_time, id, act);
		pthread_mutex_unlock(&d->print_lock);
		return ;
	}
	pthread_mutex_unlock(&d->check_death);
	pthread_mutex_unlock(&d->print_lock);
}
