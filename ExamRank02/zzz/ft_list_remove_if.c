/*
This function takes as input a pointer to the pointer of the first node
of a linked list (`begin_list`), a pointer to the reference data (`data_ref`),
and a pointer to a comparison function (`cmp`).
The `cmp` function takes two data pointers and returns 0 if the data are equal,
and a non-zero value if they are different.

The `ft_list_remove_if` function traverses the linked list and removes all nodes
whose data match `data_ref`. It uses recursion to advance through the list and
remove the necessary nodes.

1. If the list is empty or the pointer to the start of the list is NULL,
the function returns without doing anything.
2. If the current node should be removed (according to the comparison function),
it saves the node in `temp`, advances the pointer to the next node,
frees the current node, and recursively calls `ft_list_remove_if`.
3. If the current node should not be removed, it recursively calls
`ft_list_remove_if` with the next node.

NOTE: You have to use (but not upload) the ft_list.h file, which will contain:
$>cat ft_list.h
typedef struct      s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
$> */

#include "ft_list.h"

int cmp(void *lst, void *data_ref)
{
    if(lst->data == data_ref)
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list	*temp;

	if (!begin_list || !*begin_list)
		return (NULL);
	while (*begin_list)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			temp = *begin_list;
			begin_list = (*begin_list)->next;
			free(temp);
		}
	}
}

int	main(void)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->data = "H";
	lst->next = (t_list *)malloc(sizeof(t_list));
	lst->next->data = "O";
	lst->next->next = (t_list *)malloc(sizeof(t_list));
    lst->next->next->data = "L";
    lst->next->next->next = NULL;

    char *data_ref = "O";


}