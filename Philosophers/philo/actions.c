/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:20:22 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 17:20:22 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo->list, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print(philo->list, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
	}
	ft_print(philo->list, philo->id, "has taken a fork");
	ft_print(philo->list, philo->id, "is eating");
	pthread_mutex_lock(&philo->list->check_meal);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->list->check_meal);
	ft_usleep(philo->list->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->list->check_meal);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->list->check_meal);
}

void	philo_sleep(t_philo *philo)
{
	ft_print(philo->list, philo->id, "is sleeping");
	ft_usleep(philo->list->time_to_sleep);
}

void	think(t_philo *philo)
{
	ft_print(philo->list, philo->id, "is thinking");
}

int	eat_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->list->check_meal);
	if (philo->list->must_eat_count > 0
		&& philo->eat_count >= philo->list->must_eat_count)
	{
		pthread_mutex_unlock(&philo->list->check_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->list->check_meal);
	return (0);
}

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo->list, philo->id, "has taken a fork");
	ft_usleep(philo->list->time_to_die);
	ft_print(philo->list, philo->id, "died");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->list->check_death);
	philo->list->stop = 1;
	pthread_mutex_unlock(&philo->list->check_death);
}
