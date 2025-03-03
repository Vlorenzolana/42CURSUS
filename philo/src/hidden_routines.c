/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:34:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/03 19:43:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_flag(t_table *table, bool state)
{
	pthread_mutex_lock(&table->lock_sim_stop);
	table->sim_stop = state;
	pthread_mutex_unlock(&table->lock_sim_stop);
}

bool	sim_stopped(t_table *table)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&table->lock_sim_stop);
	if (table->sim_stop == true)
		r = true;
	pthread_mutex_unlock(&table->lock_sim_stop);
	return (r);
}

static bool	end_condition_reached(t_table *table)
{
	unsigned int	i;
	bool			all_ate_enough;

	all_ate_enough = true;
	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_lock(&table->philos[i]->lock_meal_time);
		if (phil_kill(table->philos[i]))
			return (true);
		if (table->must_eat_count != -1)
			if (table->philos[i]->times_ate < (unsigned int)table->must_eat_count)
				all_ate_enough = false;
		pthread_mutex_unlock(&table->philos[i]->lock_meal_time);
		i++;
	}
	if (table->must_eat_count != -1 && all_ate_enough == true)
	{
		sim_flag(table, true);
		return (true);
	}
	return (false);
}

static bool	phil_kill(t_philo *philo)
{
	time_t	time;

	time = time_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		sim_flag(philo->table, true);
		status_write(philo, true, DIED);
		pthread_mutex_unlock(&philo->lock_meal_time);
		return (true);
	}
	return (false);
}

void	*hidden_routines(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->must_eat_count == 0)
		return (NULL);
	sim_flag(table, false);
	sim_start_delay(table->start_time);
	while (true)
	{
		if (end_condition_reached(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

/* sim_flag:
 *	Sets the simulation stop flag to true or false. Only the grim
 *	reaper thread can set this flag. If the simulation stop flag is
 *	set to true, that means the simulation has met an end condition.
 *
 *	sim_stopped:
 *	Checks whether the simulation is at an end. The stop flag
 *	is protected by a mutex lock to allow any thread to check
 *	the simulation status without conflict.
 *	Returns true if the simulation stop flag is set to true,
 *	false if the flag is set to false.
 *
 *	phil_kill:
 *	Checks if the philosopher must be killed by comparing the
 *	time since the philosopher's last meal and the time_to_die parameter.
 *	If it is time for the philosopher to die, sets the simulation stop
 *	flag and displays the death status.
 *	Returns true if the philosopher has been killed, false if not.
 *
 *	end_condition_reached:
 *	Checks each philosopher to see if one of two end conditions
 *	has been reached. Stops the simulation if a philosopher needs
 *	to be killed, or if every philosopher has eaten enough.
 *	Returns true if an end condition has been reached, false if not.
 *
 *	routine:
 *	The hidden routines thread's routine. Checks if a philosopher must
 *	be killed and if all philosophers ate enough. If one of those two
 *	end conditions are reached, it stops the simulation.
 */