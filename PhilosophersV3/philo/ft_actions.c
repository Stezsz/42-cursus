/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:40:05 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/27 16:40:05 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_list *d, int i)
{
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_r]);
	printer(calc_time() - d->s_time, i + 1, "has taken a fork");
	if (d->num_philos == 1)
		ft_usleep(d->time_die + 1);
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_l]);
	printer(calc_time() - d->s_time, i + 1, "has taken a fork");
}

void	ft_eat(t_list *d, int i)
{
	printer(calc_time() - d->s_time, i + 1, "is eating");
	d->philo[i].num_eats++;
	ft_usleep(d->time_eat);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_l]);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_r]);
	pthread_mutex_lock(&d->mutex_last_eat);
	d->philo[i].last_eat = calc_time() - d->s_time;
	pthread_mutex_unlock(&d->mutex_last_eat);
}

void	ft_sleep(t_list *d, int i)
{
	printer(calc_time() - d->s_time, i + 1, "is sleeping");
	ft_usleep(d->time_sleep);
	printer(calc_time() - d->s_time, i + 1, "is thinking");
}
