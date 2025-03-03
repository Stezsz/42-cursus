/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:17:09 by strodrig          #+#    #+#             */
/*   Updated: 2025/01/07 11:17:09 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum e_bool
{
	false,
	true
};

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				should_die;
	long long		last_meal;
	t_info			*info;
	pthread_t		thread;
}	t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo;
	int				num_of_times_eaches_philo_must_eat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_lock;
}	t_info;

/*----- ACTIONS -----*/
void	ft_print_msg(t_philo *philo, char *msg);
void	ft_join_free(t_info *info);
void	*philosophers(void *arg);
void	grab_fork(t_philo *philo, int fork);
void	down_forks(t_philo *philo, int right_fork, int left_fork);
void	ft_eat(t_philo *philo);
void	sleep_and_think(t_philo *philo);

/*----- INIT -----*/
int		ft_init_info(t_info *info, int ac, char **av);
int		ft_check_info(t_info info, int ac);
void	ft_get_args(t_info *info, int ac, char **av);
void	ft_init_mutex(t_info *info);
void	ft_create_philo(t_info *info);
void	*ft_check_ate(void *arg);
void	*ft_check_death(void *arg);

/*----- UTILS -----*/
int		ft_puterror(char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
long	ft_get_time(void);
long	ft_current_time(t_info *info);

#endif
