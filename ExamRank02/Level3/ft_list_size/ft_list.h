#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char		    *data;
	struct s_list	*next;
}	t_list;

#endif