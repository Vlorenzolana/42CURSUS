/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:08:46 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/03 19:48:45 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	status_debug(t_philo *philo, char *color, char *str,
		t_status status)
{
	if (status == GOT_FORK_1)
		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n", time_ms()
			- philo->table->start_time, color, philo->id + 1, str,
			philo->fork[0]);
	else if (status == GOT_FORK_2)
		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n", time_ms()
			- philo->table->start_time, color, philo->id + 1, str,
			philo->fork[1]);
	else
		printf("[%10ld]\t%s%03d\t%s\e[0m\n", time_ms()
			- philo->table->start_time, color, philo->id + 1, str);
}

static void	status_write(t_philo *philo, t_status status)
{
	if (status == DIED)
		status_debug(philo, RED, "died", status);
	else if (status == EATING)
		status_debug(philo, GREEN, "is eating", status);
	else if (status == SLEEPING)
		status_debug(philo, CYAN, "is sleeping", status);
	else if (status == THINKING)
		status_debug(philo, CYAN, "is thinking", status);
	else if (status == GOT_FORK_1)
		status_debug(philo, PURPLE, "has taken a fork", status);
	else if (status == GOT_FORK_2)
		status_debug(philo, PURPLE, "has taken a fork", status);
}

static void	status_print(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", time_ms() - philo->table->start_time, philo->id + 1,
		str);
}

void	status_write(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->table->lock_write);
	if (sim_stopped(philo->table) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->table->lock_write);
		return ;
	}
	if (DEBUG_FORMATTING == true)
	{
		status_write(philo, status);
		pthread_mutex_unlock(&philo->table->lock_write);
		return ;
	}
	if (status == DIED)
		status_print(philo, "died");
	else if (status == EATING)
		status_print(philo, "is eating");
	else if (status == SLEEPING)
		status_print(philo, "is sleeping");
	else if (status == THINKING)
		status_print(philo, "is thinking");
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		status_print(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->lock_write);
}

void	sim_outcome(t_table *table)
{
	unsigned int	i;
	unsigned int	full_count;

	full_count = 0;
	i = 0;
	while (i < table->num_philo)
	{
		if (table->philos[i]->times_ate >= (unsigned int)table->must_eat_count)
			full_count++;
		i++;
	}
	pthread_mutex_lock(&table->lock_write);
	printf("%d/%d philosophers had at least %d meals.\n", full_count,
		table->num_philo, table->must_eat_count);
	pthread_mutex_unlock(&table->lock_write);
	return ;
}

/* status_debug:
 *	Prints the philosopher's status in an easier to read,
 *	colorful format to help with debugging. For fork-taking
 *	statuses, extra information is displayed to show which fork
 *	the philosopher has taken.
 *
 *	status_write:
 *	Redirects the status writing for debug mode. For this option,
 *	the DEBUG_FORMATTING option must be set to 1 in philo.h.
 *
 *	status_print:
 *	Prints a philosopher's status in plain text as required by the project
 *	subject:
 *		timestamp_in_ms X status
 *
 *	status_write:
 *	Prints the status of a philosopher as long as the simulation is
 *	still active. Locks the write mutex to avoid intertwined messages
 *	from different threads.
 *
 *	If DEBUG_FORMATTING is set to 1 in philo.h, the status will
 *	be formatted with colors and extra information to help with debugging.
 *	Otherwise the output will be the regular format required by the project
 *	subject.
 *
 *	sim_outcome:
 *	Prints the outcome of the simulation if a number of times to
 *	eat was specified. Only used for debug purposes.
 */
