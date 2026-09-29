/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:13 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/05 17:22:20 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[0]]);
	display_status(philo, false, GOT_FORK_1);
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[1]]);
	display_status(philo, false, GOT_FORK_2);
	display_status(philo, false, EATING);
	pthread_mutex_lock(&philo->lock_meal_time);
	philo->last_meal = time_ms();
	pthread_mutex_unlock(&philo->lock_meal_time);
	philo_sleep(philo->table, philo->table->time_to_eat);
	if (sim_stopped(philo->table) == false)
	{
		pthread_mutex_lock(&philo->lock_meal_time);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->lock_meal_time);
	}
	display_status(philo, false, SLEEPING);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[0]]);
	philo_sleep(philo->table, philo->table->time_to_sleep);
}

static void	think(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->lock_meal_time);
	time_to_think = (philo->table->time_to_die - (time_ms() - philo->last_meal)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->lock_meal_time);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == false)
		display_status(philo, false, THINKING);
	philo_sleep(philo->table, time_to_think);
}

static void	*loner_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[0]]);
	display_status(philo, false, GOT_FORK_1);
	philo_sleep(philo->table, philo->table->time_to_die);
	display_status(philo, false, DIED);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[0]]);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->lock_meal_time);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->lock_meal_time);
	sim_start_delay(philo->table->start_time);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->num_philo == 1)
		return (loner_philo(philo));
	else if (philo->id % 2)
		think(philo, true);
	while (sim_stopped(philo->table) == false)
	{
		eat_sleep(philo);
		think(philo, false);
	}
	return (NULL);
}
