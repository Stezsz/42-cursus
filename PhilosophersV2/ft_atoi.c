/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:36:55 by gemartin          #+#    #+#             */
/*   Updated: 2025/03/22 14:23:31 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	ft_spaces(char c)
{
	return (
		c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r'
	);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				valorfinal;
	long long int	nbr;

	nbr = 0;
	i = 0;
	valorfinal = 1;
	while (str[i] && ft_spaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr < INT_MIN && valorfinal == -1)
			return (0);
		if (nbr > INT_MAX && valorfinal == 1)
			return (-1);
	}
	return (nbr * valorfinal);
}
