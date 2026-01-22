/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:21:36 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:34:46 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	should_stop(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->dead);
	ret = table->stop;
	pthread_mutex_unlock(&table->dead);
	return (ret);
}

void	set_stop(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	table->stop = 1;
	pthread_mutex_unlock(&table->dead);
}
