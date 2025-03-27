/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:53:55 by strodrig          #+#    #+#             */
/*   Updated: 2025/03/24 18:53:55 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_eats;
	long			last_eat;
	int				fork_l;
	int				fork_r;
	struct s_list	*d;
}	t_philo;

typedef struct s_list
{
	int				init_philo;
	int				stat;
	int				id;
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				philo_eats;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_stat;
	pthread_mutex_t	mutex_i;
	pthread_mutex_t	mutex_msg;
	pthread_mutex_t	mutex_fork;
	long			s_time;
}	t_list;

/* ---- init_values.c ---- */
int	init_values(t_list *d);

/* ---- mtx_and_pth.c ---- */
int	create_mutex(t_list *d);
int	create_threads(t_list *d);

/* ---- main_checker.c ---- */
void	main_checker(t_list *d);
int		check_eats(t_list *d);

/* ---- printer.c ---- */
void	printer(long t, int id, char *str);

/* ---- utils ---- */
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

/* ---- ft_free.c ---- */
void	ft_free(t_list *d);

/* ---- time_utils.c ---- */
long	calc_time(void);
void	ft_usleep(long time);

/* ---- routine.c ---- */
int		routine(t_list *d);
void	*philo_routine(void *f);
int		death_philo(t_list *d);

/* ---- ft_actions.c ---- */
void	ft_take_fork(t_list *d, int i);
void	ft_eat(t_list *d, int i);
void	ft_sleep(t_list *d, int i);

#endif

