/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:44:22 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:35:21 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAX_PHILOS 200
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_philo	t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_table
{
	t_philo			*philos;
	t_fork			*fork;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				stop;
	int				feed;
	struct timeval	start_time;
	struct timeval	curr_time;
}	t_table;

typedef struct s_philo
{
	pthread_t	id;
	t_table		*table;
	int			id_philo;
	int			right;
	int			left;
	long		last_meal;
	int			n_meals;
}	t_philo;

// main.c
int		main(int ac, char **av);

// checker.c
int		checker_av(int ac, char **av);
long	ft_atoi(char *str);
int		ft_isnum(char *str);

// dinner.c
void	*dinner(void *arg);
void	*employee(void *arg);

// utils.c
void	print_status(t_philo *ph, char *msg);
void	creat_philo_thread(t_table *table);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		should_stop(t_table *table);
void	set_stop(t_table *table);
void	update_meal(t_philo *philo);
void	take_forks_ordered(t_philo *philo, int first, int second);
void	drop_forks(t_philo *philo, int first, int second);
void	one_philo_case(t_philo *philo);
void	cleanup_table(t_table *table);

// time.c
long	time_to_ms(struct timeval ms); // tempo desde 1970
long	get_time(t_table *table);
long	get_time_stamp(t_table *table);
void	precise_sleep(t_table *table, int ms);

// parse.c
t_table	*init_t_table(int ac, char **av);
int		*init_t_philo(t_table *table);

#endif
