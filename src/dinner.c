/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:46:02 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:28:45 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_death(t_table *table);
static int	check_full(t_table *table);
static void	dinner_aux(t_table *table, t_philo *philo, int first, int second);

void	*dinner(void *arg)
{
	t_philo	*philo;
	t_table	*table;
	int		first;
	int		second;

	philo = (t_philo *)arg;
	table = philo->table;
	if (table->n_philos == 1)
		return (one_philo_case(philo), NULL);
	first = ft_min(philo->left, philo->right);
	second = ft_max(philo->left, philo->right);
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (!should_stop(table))
		dinner_aux(table, philo, first, second);
	return (NULL);
}

void	*employee(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (!should_stop(table))
	{
		if (check_full(table))
			break ;
		if (check_death(table))
			break ;
		usleep(500);
	}
	return (NULL);
}

static void	dinner_aux(t_table *table, t_philo *philo, int first, int second)
{
	long	remain;
	long	now;
	long	last_meal;

	take_forks_ordered(philo, first, second);
	update_meal(philo);
	print_status(philo, "is eating");
	precise_sleep(table, table->time_to_eat);
	drop_forks(philo, first, second);
	print_status(philo, "is sleeping");
	precise_sleep(table, table->time_to_sleep);
	print_status(philo, "is thinking");
	pthread_mutex_lock(&table->eat);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&table->eat);
	now = get_time_stamp(table);
	remain = table->time_to_die - (now - last_meal);
	if (remain > table->time_to_eat)
		usleep(1000);
}

static int	check_full(t_table *table)
{
	int	i;
	int	full;
	int	meals;

	if (table->must_eat == -1)
		return (0);
	full = 0;
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->eat);
		meals = table->philos[i].n_meals;
		pthread_mutex_unlock(&table->eat);
		if (meals >= table->must_eat)
			full++;
		i++;
	}
	if (full == table->n_philos)
	{
		set_stop(table);
		return (1);
	}
	return (0);
}

static int	check_death(t_table *table)
{
	int		i;
	long	now;
	long	last;

	now = get_time_stamp(table);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->eat);
		last = table->philos[i].last_meal;
		pthread_mutex_unlock(&table->eat);
		if ((now - last) >= table->time_to_die)
		{
			set_stop(table);
			pthread_mutex_lock(&table->print);
			printf("%ld %d died\n", now, table->philos[i].id_philo);
			pthread_mutex_unlock(&table->print);
			return (1);
		}
		i++;
	}
	return (0);
}
