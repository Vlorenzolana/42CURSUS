/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:35:08 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/05 17:22:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	start_sim(t_table *table)
{
	unsigned int	i;
	unsigned int	delay;

	delay = table->num_philo * 20;
	table->start_time = time_ms() + delay;
	i = 0;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, &philo_routine,
				table->philos[i]) != 0)
			return (error_failure("%s error: Could not create thread.\n", NULL,
					table));
		i++;
	}
	if (table->num_philo > 1)
	{
		if (pthread_create(&table->waiter_routine, NULL, &waiter_routine,
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
		pthread_join(table->waiter_routine, NULL);
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
				NULL, EXIT_FAILURE));
	if (!valid_args(ac, av))
		return (EXIT_FAILURE);
	table = init_table(ac, av, 1);
	if (!table)
		return (EXIT_FAILURE);
	if (!start_sim(table))
		return (EXIT_FAILURE);
	stop_simulation(table);
	return (EXIT_SUCCESS);
}
