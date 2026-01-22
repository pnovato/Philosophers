/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:20:11 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:34:15 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	update_meal(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->eat);
	philo->last_meal = get_time_stamp(table);
	philo->n_meals++;
	pthread_mutex_unlock(&table->eat);
}

void	take_forks_ordered(t_philo *philo, int first, int second)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->fork[first].fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&table->fork[second].fork);
	print_status(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo, int first, int second)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_unlock(&table->fork[second].fork);
	pthread_mutex_unlock(&table->fork[first].fork);
}

void	one_philo_case(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->fork[philo->left].fork);
	print_status(philo, "has taken a fork");
	precise_sleep(table, table->time_to_die);
	pthread_mutex_unlock(&table->fork[philo->left].fork);
}

void	cleanup_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->eat);
	pthread_mutex_destroy(&table->dead);
	free(table->fork);
	free(table->philos);
	free(table);
}
