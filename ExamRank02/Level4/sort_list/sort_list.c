/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int	ascending(int a, int b)
{
	return (a <= b);
}
*/

#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*start;

	start = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if ((cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}
/* 
//
// main function
//
t_list	*add_int(t_list *list, int nb)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = nb;
	new->next = list;
	return (new);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	list = add_int(list, 9);
	list = add_int(list, 3);
	list = add_int(list, 2);
	list = add_int(list, 4);
	list = add_int(list, 1);
	list = sort_list(list, &ascending);
	while (list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);
} */

// Bubble sort https: // www.youtube.com/watch?v=Dv4qLJcxus8
// https://pythontutor.com/render.html#mode=edit
