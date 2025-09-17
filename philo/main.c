#include "philo.h"

int main (int ac, char **av)
{
	(void)av;
	if (ac < 4 || ac > 5)
	{
		printf("Usage: ./philo n_philo t_die t_eat t_sleep optional[must_eat]\n");
		return (1);
	}
	//philosophers(av);
	example();
	return (0);
}
