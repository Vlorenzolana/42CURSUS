#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	if (*begin_list == NULL || begin_list == NULL)
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
		*begin_list = (*begin_list)->next;
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
}

void	free_list(t_list *list)
{
	t_list *tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
t_list	*create_node(void *data)
{
	t_list	*new_node;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d -> ", *(int *)list->data);
		list = list->next;
	}
	printf("\n");
}
int	cmp(void *data1, void *data2)
{
	int	tmp;

	tmp = *(int *)data1 - *(int *)data2;
	return (tmp);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	int		data1;
	int		data2;
	int		data3;
	int		data4;
	int		target;
	t_list	*current;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	data4 = 4;
	node1 = create_node(&data1);
	node2 = create_node(&data2);
	node3 = create_node(&data3);
	node4 = create_node(&data4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	current = node1;
	printf("Original list:\n");
	print_list(node1);
	node1 = current;
	target = 2;
	ft_list_remove_if(&node1, &target, cmp);
	printf("List after removing %d:\n", target);
	print_list(node1);
	free_list(current);
	return (0);
}
