/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:34:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/05 13:42:01 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

static bool	phil_kill(t_philo *philo)
{
	time_t	time;

	time = time_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		sim_flag(philo->table, true);
		display_status(philo, true, DIED);
		pthread_mutex_unlock(&philo->lock_meal_time);
		return (true);
	}
	return (false);
}

static bool	condition_met(t_table *table)
{
	unsigned int i;
	bool satisfied;

	satisfied = true;
	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_lock(&table->philos[i]->lock_meal_time);
		if (phil_kill(table->philos[i]))
			return (true);
		if (table->eat_count != -1)
			if (table->philos[i]->times_ate < (unsigned int)table->eat_count)
				satisfied = false;
		pthread_mutex_unlock(&table->philos[i]->lock_meal_time);
		i++;
	}
	if (table->eat_count != -1 && satisfied == true)
	{
		sim_flag(table, true);
		return (true);
	}
	return (false);
}

void	*waiter_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->eat_count == 0)
		return (NULL);
	sim_flag(table, false);
	sim_start_delay(table->start_time);
	while (true)
	{
		if (condition_met(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
