/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:35:49 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/26 18:35:49 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer(long t, int id, char *str)
{
	if (ft_strcmp(str, "died") == 0)
	{
		printf("%ld %d %s\n", t, id, str);
	}
	else if (ft_strcmp(str, "has taken a fork") == 0)
	{
		printf("%ld %d %s\n", t, id, str);
	}
	else if (ft_strcmp(str, "is eating") == 0)
	{
		printf("%ld %d %s\n", t, id, str);
	}
	else if (ft_strcmp(str, "is sleeping") == 0)
	{
		printf("%ld %d %s\n", t, id, str);
	}
	else if (ft_strcmp(str, "is thinking") == 0)
	{
		printf("%ld %d %s\n", t, id, str);
	}
}
