/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnovato- <pnovato-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:40:23 by pnovato-          #+#    #+#             */
/*   Updated: 2026/01/22 18:37:35 by pnovato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	checker_av(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("./philo n_philo t_die t_eat t_sleep n_eat\n"), 1);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf("Error: Invalid number_of_philosophers\n"));
	if (ft_atoi(av[2]) <= 0 || ft_isnum(av[2]))
		return (printf("Error: Invalid time_to_die\n"));
	if (ft_atoi(av[3]) <= 0 || ft_isnum(av[3]))
		return (printf("Error: Invalid time_to_eat\n"));
	if (ft_atoi(av[4]) <= 0 || ft_isnum(av[4]))
		return (printf("Error: Invalid time_to_sleep\n"));
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_isnum(av[5])))
		return (printf("Error: Invalid must_eat\n"));
	return (0);
}

long	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i++] > '9')
			return (1);
	}
	return (0);
}
