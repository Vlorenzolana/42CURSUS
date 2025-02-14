#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif