/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:21:44 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 13:21:44 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
	free(info->philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->finish_lock);
	free(info->forks);
	free(info);
}
