//
//
//
// THIS IS A VERY INITAL TEST
//
//
//
//
//

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_assets
{
	char			*str;
	pthread_mutex_t	mutex;
}					t_assets;

#endif