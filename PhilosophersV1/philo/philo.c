/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:02 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 11:16:02 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 5 && ac != 6)
	{
		return (ft_puterror("Usage: ./philo number_of_philosophers"
				"time_to_die time_to_eat time_to_sleep"
				"[number_of_times_each_philosopher_must_eat]"));
	}
	info = ft_calloc(1, sizeof(*info));
	if (ft_init_info(info, ac, av) == 0)
		ft_join_free(info);
	return (0);
}
