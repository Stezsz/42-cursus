/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:22:44 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/14 19:22:44 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_integer(char **av, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_int(av[i]) || av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
