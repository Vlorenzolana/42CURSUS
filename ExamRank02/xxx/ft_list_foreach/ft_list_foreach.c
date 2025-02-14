#include "ft_list.h"

void	toupper_node(t_list *begin)
{
	char	*str;

	str = (char *)(begin->data);
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
	}
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

int	main(void)
{
	t_list *head = ft_newnode("Hello");
	head->next = ft_newnode("World");
	head->next->next = ft_newnode("Hola");
	head->next->next->next = ft_newnode("Quease");

	ft_list_foreach(head, toupper_node);

	t_list *current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->data);
		current = current->next;
	}

	t_list *next;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	return (0);
}