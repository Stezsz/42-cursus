/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:43:50 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/26 18:43:50 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	calc_time(void)
{
	struct timeval	tv;
	long			actual_time;

	gettimeofday(&tv, NULL);
	actual_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (actual_time);
}

void	ft_usleep(long milliseconds)
{
	long	start_time;

	start_time = calc_time();
	while ((calc_time() - start_time) < milliseconds)
		usleep(10);
}
