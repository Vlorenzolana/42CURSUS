#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	//	t_list	*tmp;
	int		size;

	while (begin_list)
	{
	//	tmp = begin_list;
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

t_list	*create_node(int *data_init)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data_init;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list *list;
	int size;

	int data_init = 0;
	list = create_node(&data_init);
	list->next = create_node(&data_init);
	list->next->next = create_node(&data_init);

	size = ft_list_size(list);

	printf("%d\n", size);
	return (0);
}