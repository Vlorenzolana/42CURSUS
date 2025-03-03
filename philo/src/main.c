/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:35:08 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/03 19:55:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	start_sim(t_table *table)
{
	unsigned int	i;

	table->start_time = time_ms() + (table->num_philo * 2 * 10);
	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, &philosopher,
				table->philos[i]) != 0)
			return (error_failure("%s error: Could not create thread.\n", NULL,
					table));
		i++;
	}
	if (table->num_philo > 1)
	{
		if (pthread_create(&table->hidden_routines, NULL, &hidden_routines,
				table) != 0)
			return (error_failure("%s error: Could not create thread.\n", NULL,
					table));
	}
	return (true);
}

static void	stop_simulation(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->num_philo > 1)
		pthread_join(table->hidden_routines, NULL);
	if (DEBUG_FORMATTING == true && table->must_eat_count != -1)
		sim_outcome(table);
	mutex_destroy(table);
	free_table(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac - 1 < 4 || ac - 1 > 5)
		return (msg("%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n",
					NULL,
					EXIT_FAILURE));
	if (!valid_args(ac, av))
		return (EXIT_FAILURE);
	table = table_init(ac, av, 1);
	if (!table)
		return (EXIT_FAILURE);
	if (!start_sim(table))
		return (EXIT_FAILURE);
	stop_simulation(table);
	return (EXIT_SUCCESS);
}
/* start_sim:
 *	Launches the simulation by creating a hidden routines thread as well as
 *	one thread for each philosopher.
 *	Returns true if the simulation was successfully started, false if there
 *	was an error.
 *
 *  stop_simulation:
 *	Waits for all threads to be joined then destroys mutexes and frees
 *	allocated memory.
 */