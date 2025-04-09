/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:07 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/07 16:55:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_list *d)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	d->start_time = get_time();
	while (i < d->num_philos)
	{
		pthread_create(&d->philos[i].thread, NULL, &routine, &d->philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, &monitor_philos, d);
	i = 0;
	while (i < d->num_philos)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

void	init_mutexes(t_list	*d, int ac, char **av)
{
	int	i;

	i = 0;
	d->num_philos = ft_atoi(av[1]);
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		d->must_eat_count = ft_atoi(av[5]);
	else
		d->must_eat_count = -1;
	d->stop = 0;
	d->forks = malloc(d->num_philos * sizeof(pthread_mutex_t));
	d->philos = malloc(d->num_philos * sizeof(t_philo));
	pthread_mutex_init(&d->check_meal, NULL);
	pthread_mutex_init(&d->check_death, NULL);
	pthread_mutex_init(&d->print_lock, NULL);
	pthread_mutex_init(&d->lock, NULL);
	d->odd = 1;
	while (i < d->num_philos)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_list	*d, int ac, char **av)
{
	int	i;

	init_mutexes(d, ac, av);
	i = 0;
	while (i < d->num_philos)
	{
		d->philos[i].id = i + 1;
		d->philos[i].left_fork = &d->forks[i];
		d->philos[i].right_fork = &d->forks[(i + 1) % d->num_philos];
		d->philos[i].last_meal_time = get_time();
		d->philos[i].eat_count = 0;
		d->philos[i].list = d;
		i++;
	}
}
