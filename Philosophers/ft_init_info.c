/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:04:32 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 12:04:32 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_info(t_info info, int ac)
{
	if (ac == 6 && info.num_of_times_eaches_philo_must_eat <= 0)
		return (ft_puterror("Error: wrong number of must eat"));
	if (info.num_of_philo < 0)
		return (ft_puterror("Error: wrong number of philosophers"));
	if (info.time_to_die < 60)
		return (ft_puterror("Error: time to die must be at least 60"));
	if (info.time_to_eat < 60)
		return (ft_puterror("Error: time to eat must be at least 60"));
	if (info.time_to_sleep < 60)
		return (ft_puterror("Error: time to sleep must be at least 60"));
	return (0);
}

void	ft_get_args(t_info *info, int ac, char **av)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_of_times_eaches_philo_must_eat = ft_atoi(av[5]);
	else
		info->num_of_times_eaches_philo_must_eat = -1;
}

int	ft_init_info(t_info *info, int ac, char **av)
{
	if (!info)
		return (1);
	ft_get_args(info, ac, av);
	if (ft_check_info(*info, ac))
		return (1);
	info->philo = ft_calloc(info->num_of_philo, sizeof(t_philo));
	info->forks = ft_calloc(info->num_of_philo,
				sizeof(pthread_mutex_t));
	if (!info->philo || !info->forks)
		return (1);
	info->finish = false;
	info->all_ate = 0;
	ft_init_mutex(info);
	ft_create_philo(info);
	return (0);
}

