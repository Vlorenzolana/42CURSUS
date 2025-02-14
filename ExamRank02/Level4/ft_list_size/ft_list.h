/*
struct				s_list
{
	int				data;
	t_list			*next;
}; */

/*
typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;
 */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;
#endif
