/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:44:14 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:29:19 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_table		*table;
	pthread_t	monitor;
	int			i;

	if (checker_av(ac, av) == 1)
		return (1);
	table = init_t_table(ac, av);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_init(&table->eat, NULL);
	pthread_mutex_init(&table->print, NULL);
	init_t_philo(table);
	if (pthread_create(&monitor, NULL, employee, table) != 0)
		return (printf("Erro pthread_create monitor\n"), 1);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i].id, NULL);
		i++;
	}
	cleanup_table(table);
	return (0);
}
