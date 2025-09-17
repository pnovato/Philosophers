#include "../philo.h"

void	parse(char **av)
{
	t_data	*data;

	data->n_philos = av[1];
	data->time_to_die = av[2];
	data->time_to_eat = av[3];
	data->time_to_sleep = av[4];

}
