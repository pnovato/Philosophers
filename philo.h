#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int		id;
	pthread_t	thread;
	long	last_meal;
	int		meals_eaten;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;	
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int		n_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		start_time;
	int		must_eat;
	int		philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
}	t_data;

#endif
