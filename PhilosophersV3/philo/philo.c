/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:49 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 12:13:49 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_num_arg(char *num_arg, int pos, t_list *d)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (pos == 1 && n > 200) || (pos == 2 && n < 60)
		|| (pos == 3 && n < 60) || (pos == 4 && n < 60))
	{
		ft_free(d);
		printf("Error: Invalid argument\n");
		return (-1);
	}
	else
	{
		if (pos == 1)
			d->num_philos = n;
		if (pos == 2)
			d->time_die = n;
		if (pos == 3)
			d->time_eat = n;
		if (pos == 4)
			d->time_sleep = n;
		if (pos == 5)
			d->philo_eats = n;
		return (n);
	}
}

static int	start_philo(t_list *d)
{
	pthread_mutex_init(&d->mutex_last_eat, NULL);
	pthread_mutex_init(&d->mutex_stat, NULL);
	d->stat = 0;
	d->id = 1;
	if (init_values(d) == -1)
		return (-1);
	if (create_mutex(d) == -1)
		return (-1);
	d->s_time = calc_time();
	if (create_threads(d) == -1)
		return (-1);
	d->init_philo = 1;
	main_checker(d);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*d;

	if (argc != 5 && argc != 6)
	{
		return (printf(
				"Usage: ./philo <num_of_philos> <time_to_die> <time_to_eat>"
				"<time_to_sleep> [num_of_times_each_philo_must_eat]\n"
			));
	}
	i = 1;
	d = (t_list *)malloc(sizeof(t_list));
	if (!d)
		return (0);
	d->philo_eats = 0;
	while (i != argc)
	{
		if (check_num_arg(argv[i], i, d) < 0)
			return (0);
		i++;
	}
	if (start_philo(d) != 0)
		return (-1);
	ft_free(d);
	return (0);
}
