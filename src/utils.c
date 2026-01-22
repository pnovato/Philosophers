/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:47:30 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:33:23 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_status(t_philo *philo, char *msg)
{
	long	ts;
	t_table	*table;

	table = philo->table;
	if (should_stop(table))
		return ;
	pthread_mutex_lock(&table->print);
	if (!should_stop(table))
	{
		ts = get_time_stamp(table);
		printf("%ld %d %s\n", ts, philo->id_philo, msg);
	}
	pthread_mutex_unlock(&table->print);
}

void	creat_philo_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].id, NULL, dinner,
				&table->philos[i]) != 0)
		{
			printf("Erro ao fazer pthread_creat: creat_philo_thread\n");
			free(table);
		}
		i++;
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
