/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:25:23 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 13:25:23 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	while (!philo->should_die && !philo->info->finish)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->info->num_of_philo;
		if (philo->id % 2 == 0)
		{
			grab_fork(philo, right_fork);
			grab_fork(philo, left_fork);
		}
		else
		{
			grab_fork(philo, left_fork);
			grab_fork(philo, right_fork);
		}
		ft_eat(philo);
		down_forks(philo, right_fork, left_fork);
		sleep_and_think(philo);
	}
	return (NULL);
}
