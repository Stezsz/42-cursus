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

void	ft_eat(t_philo *philo)
{
	ft_print_msg(philo, "is eating");
	usleep(philo->info->time_to_eat * 1000);
	philo->last_meal = ft_get_time();
	philo->ate++;
	if (philo->ate == philo->info->num_of_times_eaches_philo_must_eat)
		philo->info->all_ate++;
}

void	sleep_and_think(t_philo *philo)
{
	ft_print_msg(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
	ft_print_msg(philo, "is thinking");
}
