/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:47:30 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/21 20:53:44 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_table(t_table *table)
{
	int i;

	i = 0;
	printf("int n_philos: %d\n", table->n_philos);
	while (i < table->n_philos)
	{
		printf("Philo Number: %d\n", i + 1);
		printf("t_philo *philos: %p\n", &table->philos[i]);
		printf("t_fork *fork: %p\n", &table->fork[i]);
		i++;
	}
	printf("int time_to_die: %d\n", table->time_to_die);
	printf("int time_to_eat: %d\n", table->time_to_eat);
	printf("int time_to_sleep: %d\n", table->time_to_sleep);
	printf("int must_eat: %d\n", table->must_eat);
}

void print_status(t_philo *philo, char *msg)
{
	long ts;
	t_table *table;

	table = philo->table;
	if (should_stop(table))
		return;
	pthread_mutex_lock(&table->print);
	if (!should_stop(table))
	{
		ts = get_time_stamp(table);
		printf("%ld %d %s\n", ts, philo->id_philo, msg);
	}
	pthread_mutex_unlock(&table->print);
}

void creat_philo_thread(t_table *table)
{
	int i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].id, NULL, dinner, &table->philos[i]) != 0)
		{
			printf("Erro ao fazer pthread_creat: creat_philo_thread\n");
			free(table);
		}
		i++;
	}
}

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int should_stop(t_table *table)
{
	int ret;

	pthread_mutex_lock(&table->dead);
	ret = table->stop;
	pthread_mutex_unlock(&table->dead);
	return (ret);
}

void set_stop(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	table->stop = 1;
	pthread_mutex_unlock(&table->dead);
}

void update_meal(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&table->eat);
	philo->last_meal = get_time_stamp(table);
	philo->n_meals++;
	pthread_mutex_unlock(&table->eat);
}

void take_forks_ordered(t_philo *philo, int first, int second)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&table->fork[first].fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&table->fork[second].fork);
	print_status(philo, "has taken a fork");
}

void drop_forks(t_philo *philo, int first, int second)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_unlock(&table->fork[second].fork);
	pthread_mutex_unlock(&table->fork[first].fork);
}

void one_philo_case(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&table->fork[philo->left].fork);
	print_status(philo, "has taken a fork");
	precise_sleep(table, table->time_to_die);
	pthread_mutex_unlock(&table->fork[philo->left].fork);
}

void cleanup_table(t_table *table)
{
	int i;

	if (!table)
		return;
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
