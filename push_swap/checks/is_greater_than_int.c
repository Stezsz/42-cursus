/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_greater_than_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:22:43 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/14 19:22:43 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_greater(char *arg)
{
	return (ft_atoi(arg) < INT_MIN || ft_atoi(arg) > INT_MAX);
}

int	is_greater_than_int(char **av, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_greater(av[i]))
			return (1);
		i++;
	}
	return (0);
}
