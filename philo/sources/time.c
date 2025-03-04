/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:36:42 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/04 15:34:41 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	// long time_t for avoiding overflow
}

void	philo_sleep(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = time_ms() + sleep_time;
	while (time_ms() < wake_up)
	{
		if (sim_stopped(table))
			break ;
		usleep(100);
	}
}

void	sim_start_delay(time_t start_time)
{
	while (time_ms() < start_time)
		continue ;
}

/* time_ms:
 *	Gets the current time in miliseconds
 *	since 1970-01-01 at 00:00:00.
 *	Returns the time value.
 *
 *	philo_sleep:
 *	Pauses the philosopher thread for a certain amount of time in miliseconds.
 *	Periodically checks to see if the simulation has ended during the sleep
 *	time and cuts the sleep short if it has.
 *
 *	sim_start_delay:
 *	Waits for a small delay at the beginning of each threads execution
 *	so that all threads start at the same time with the same start time
 *	reference. This ensures the hidden routines thread is synchronized with
 *	the philosopher threads.
 */