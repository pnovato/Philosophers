/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:39:48 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:30:52 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	time_to_ms(struct timeval ms)
{
	return ((ms.tv_sec * 1000) + (ms.tv_usec / 1000));
}

long	get_time(t_table *table)
{
	gettimeofday(&table->curr_time, NULL);
	return (time_to_ms(table->curr_time));
}

long	get_time_stamp(t_table *table)
{
	return (get_time(table) - time_to_ms(table->start_time));
}

void	precise_sleep(t_table *table, int ms)
{
	long	start;

	start = get_time_stamp(table);
	while (!should_stop(table))
	{
		if (get_time_stamp(table) - start >= ms)
			break ;
		usleep(200);
	}
}
