/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:08:46 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/05 17:21:15 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	status_print(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", time_ms() - philo->table->start_time, philo->id + 1,
		str);
}

void	display_status(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->table->lock_write);
	if (sim_stopped(philo->table) == true && reaper_report == false)
	{
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
