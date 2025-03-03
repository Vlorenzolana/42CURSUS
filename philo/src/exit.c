/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:31:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/03 19:53:17 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_table(t_table *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->fork_locks != NULL)
		free(table->fork_locks);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->num_philo)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}

void	mutex_destroy(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->fork_locks[i]);
		pthread_mutex_destroy(&table->philos[i]->lock_meal_time);
		i++;
	}
	pthread_mutex_destroy(&table->lock_write);
	pthread_mutex_destroy(&table->lock_sim_stop);
}

int	msg(char *str, char *detail, int exit_num)
{
	if (!detail)
		printf(str, "philo:");
	else
		printf(str, "philo:", detail);
	return (exit_num);
}

int	error_failure(char *str, char *details, t_table *table)
{
	if (table != NULL)
		free_table(table);
	return (msg(str, details, 0));
}

void	*free_error(char *str, char *details, t_table *table)
{
	if (table != NULL)
		free_table(table);
	msg(str, details, EXIT_FAILURE);
	return (NULL);
}

/* free_table:
 *	Frees all of the memory allocated by the program.
 *	Returns a NULL pointer if there is nothing to free,
 *	or when all memory has been freed.
 *
 *	destroy_mutexts:
 *	Destroys every mutex created by the program: fork locks, meal locks,
 *	the write and simulation stopper lock.
 *
 *	msg:
 *	Writes a message to the console. Returns the provided exit number.
 *	Used for error management.
 *
 *	error_failure:
 *	Frees any allocated memory, prints an error message and
 *	returns 0 to indicate failure.
 *	Used for error management during initialization.
 *
 *	free_error:
 *	Frees any allocated memory, prints an error message and returns a
 *	NULL pointer.
 *	Used for error management during initialization.
 */