/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:26:56 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 16:26:56 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	numeric(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

static int	parse_args(int ac, char **av, t_list *d)
{
	if ((ac == 5 || ac == 6) && numeric(av, 0, 1))
	{
		d->num_philos = ft_atoi(av[1]);
		d->time_to_die = ft_atoi(av[2]);
		d->time_to_eat = ft_atoi(av[3]);
		d->time_to_sleep = ft_atoi(av[4]);
		d->must_eat_count = -1;
		if (ac == 6)
			d->must_eat_count = ft_atoi(av[5]);
		if (d->num_philos <= 0 || d->time_to_die <= 0 || d->time_to_eat <= 0
			|| d->time_to_sleep <= 0
			|| (d->must_eat_count != -1 && d->must_eat_count <= 0))
			return (0);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	d;

	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo <number_of_philosophers> <time_to_die> "
			"<time_to_eat> <time_to_sleep>"
			"[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!parse_args(ac, av, &d))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	init_philos(&d, ac, av);
	start_philo(&d);
	ft_free(&d);
	return (0);
}
