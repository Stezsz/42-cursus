/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:20:20 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 13:20:20 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->finish_lock);
	if (!philo->info->finish)
	{
		printf("%lld %d %s\n", ft_get_time() - philo->info->creation_time, philo->id + 1, msg);
	}
	pthread_mutex_unlock(&philo->info->finish_lock);
}
