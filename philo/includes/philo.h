/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:03:28 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/05 17:20:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS 250
# define STR_MAX_PHILOS "250"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t				start_time;
	unsigned int		num_philo;
	pthread_t			waiter_routine;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					eat_count;
	bool				sim_stop;
	pthread_mutex_t		lock_sim_stop;
	pthread_mutex_t		lock_write;
	pthread_mutex_t		*fork_locks;
	t_philo				**philos;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		lock_meal_time;
	time_t				last_meal;
	t_table				*table;
}						t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}						t_status;

//	init.c
t_table					*init_table(int ac, char **av, int i);

// parsing.c
bool					valid_args(int ac, char **av);
int						digit_str_atoi(char *str);

//	routines.c
void					*philo_routine(void *data);

//	time.c
time_t					time_ms(void);
void					philo_sleep(t_table *table, time_t sleep_time);
void					sim_start_delay(time_t start_time);

//	output.c
void					display_status(t_philo *philo, bool reaper_report,
							t_status status);

//	waiter_routine.c
void					*waiter_routine(void *data);
bool					sim_stopped(t_table *table);

//	exit.c
int						error_failure(char *str, char *details, t_table *table);
void					*free_table(t_table *table);
void					mutex_destroy(t_table *table);
void					*free_error(char *str, char *details, t_table *table);
int						msg(char *str, char *detail, int exit_num);

#endif