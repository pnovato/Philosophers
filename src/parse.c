/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:22:25 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/21 17:21:31 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_table *init_t_table(int ac, char **av)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->n_philos = (int)ft_atoi(av[1]);
	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
	{
		free(table);
		return (NULL);
	}
	table->fork = malloc(sizeof(t_fork) * table->n_philos);
	if (!table->fork)
	{
		free(table->philos);
		free(table);
		return (NULL);
	}
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	gettimeofday(&table->start_time, NULL);
	table->stop = 0;
	table->feed = 0;
	if (ac == 6)
		table->must_eat = ft_atoi(av[5]);
	else
		table->must_eat = -1;
	// print_table(table);
	return (table);
}

int *init_t_philo(t_table *table)
{
	int i;

	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].id_philo = i + 1;
		table->philos[i].left = i;
		table->philos[i].right = (i + 1) % table->n_philos; // mesa redonda, ultimo garfo e o garfo da direita do primeiro
		table->philos[i].n_meals = 0;						// comeca a zero
		table->philos[i].last_meal = get_time_stamp(table);
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->fork[i].fork, NULL) != 0)
		{
			printf("Erro no mutex: init_t_philo\n");
			free(table);
		}
		table->fork[i].id = i;
		i++;
	}
	creat_philo_thread(table);
	return (0);
}
