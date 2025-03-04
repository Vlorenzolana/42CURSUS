/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:34:55 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/04 18:28:21 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!forks)
		return (error_null("%s error: Could not allocate memory.\n", NULL, 0));
	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null("%s error: Could not create mutex.\n", NULL, 0));
		i++;
	}
	return (forks);
}

static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->num_philo);
	if (!philos)
		return (error_null("%s error: Could not allocate memory.\n", NULL, 0));
	i = 0;
	while (i < table->num_philo)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (error_null("%s error: Could not allocate memory.\n", NULL,
					0));
		if (pthread_mutex_init(&philos[i]->lock_meal_time, 0) != 0)
			return (error_null("%s error: Could not create mutex.\n", NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static bool	init_global_mutexes(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (false);
	if (pthread_mutex_init(&table->lock_sim_stop, 0) != 0)
		return (error_failure("%s error: Could not create mutex.\n", NULL,
				table));
	if (pthread_mutex_init(&table->lock_write, 0) != 0)
		return (error_failure("%s error: Could not create mutex.\n", NULL,
				table));
	return (true);
}

t_table	*init_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (error_null("%s error: Could not allocate memory.\n", NULL, 0));
	table->num_philo = integer_atoi(av[i++]);
	table->time_to_die = integer_atoi(av[i++]);
	table->time_to_eat = integer_atoi(av[i++]);
	table->time_to_sleep = integer_atoi(av[i++]);
	table->must_eat_count = -1;
	if (ac - 1 == 5)
		table->must_eat_count = integer_atoi(av[i]);
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (NULL);
	if (!init_global_mutexes(table))
		return (NULL);
	table->sim_stop = false;
	return (table);
}
