/* This function takes as input a pointer to the pointer of the first node
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

t_list	*create_node(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d -> ", *(int *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	cmp(void *data1, void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list	*temp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}

int	main(void)
{
	int		data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 5, data6 = 6;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*node6;
	int		target;

	// Create example linked list: 1 -> 2 -> 3 -> 4 -> 3 -> 5 -> NULL
	data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 3, data6 = 5;
	node1 = create_node(&data1);
	node2 = create_node(&data2);
	node3 = create_node(&data3);
	node4 = create_node(&data4);
	node5 = create_node(&data5);
	node6 = create_node(&data6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	printf("Original list:\n");
	print_list(node1);
	// Define the value to be removed
	target = 3;
	// Call ft_list_remove_if
	ft_list_remove_if(&node1, &target, cmp);
	printf("\nList after removing %d:\n", target);
	print_list(node1);
	// Free the list
	free_list(node1);
	return (0);
}
