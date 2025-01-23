/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:02:54 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 13:02:54 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->info->finish)
	{
		if ((philo->last_meal + philo->info->time_to_die) < ft_get_time())
		{
			ft_print_msg(philo, "died");
			philo->should_die = true;
			philo->info->finish = true;
		}
		usleep(100);
	}
	return (NULL);
}


void	*ft_check_ate(void *arg)
{
	t_info	*info;

	info = arg;
	while (!info->finish)
	{
		if (info->all_ate == info->num_of_philo)
		{
				info->finish = true;
		}
	}
	return (NULL);
}

void	ft_create_philo(t_info *info)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	info->creation_time = ft_get_time();
	while (i < info->num_of_philo)
	{
		info->philo[i].id = i;
		info->philo[i].ate = 0;
		info->philo[i].should_die = false;
		info->philo[i].last_meal = info->creation_time;
		info->philo[i].info = info;
		pthread_create(&info->philo[i].thread, NULL, philosophers,
				&info->philo[i]);
		pthread_create(&monitor, NULL, ft_check_death, &info->philo[i]);
		pthread_detach(monitor);
		i++;
		usleep(100);
	}
	if (info->num_of_times_eaches_philo_must_eat >= 0)
	{
		pthread_create(&monitor, NULL, ft_check_ate, info);
		pthread_detach(monitor);
	}
}

void ft_init_mutex(t_info *info)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&info->finish_lock, NULL) != 0)
	{
		ft_puterror("Error: failed to initialize finish_lock mutex");
		exit(1);
	}
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			ft_puterror("Error: failed to initialize fork mutex");
			exit(1);
		}
		i++;
	}
}
