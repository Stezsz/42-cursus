/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:31:52 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 13:31:52 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->info->forks[fork]);
	ft_print_msg(philo, "has taken a fork");
}

void	down_forks(t_philo *philo, int right_fork, int left_fork)
{
	pthread_mutex_unlock(&philo->info->forks[right_fork]);
	pthread_mutex_unlock(&philo->info->forks[left_fork]);
}

void ft_eat(t_philo *philo)
{
	struct timespec ts;

	ft_print_msg(philo, "is eating");
	ts.tv_sec = philo->info->time_to_eat / 1000;
	ts.tv_nsec = (philo->info->time_to_eat % 1000) * 1000000;
	nanosleep(&ts, NULL);
	philo->last_meal = ft_get_time();
	philo->ate++;
	if (philo->ate == philo->info->num_of_times_eaches_philo_must_eat)
	{
		pthread_mutex_lock(&philo->info->finish_lock);
		philo->info->all_ate++;
		pthread_mutex_unlock(&philo->info->finish_lock);
	}
}

void sleep_and_think(t_philo *philo)
{
	struct timespec ts;

	ft_print_msg(philo, "is sleeping");
	ts.tv_sec = philo->info->time_to_sleep / 1000;
	ts.tv_nsec = (philo->info->time_to_sleep % 1000) * 1000000;
	nanosleep(&ts, NULL);
	ft_print_msg(philo, "is thinking");
}
