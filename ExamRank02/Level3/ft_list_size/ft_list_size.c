#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		//printf("%s\n", begin_list->data);
		begin_list = begin_list->next;
		size += 1;
	}
	return (size);
}

int	main(void)
{
	t_list *lst;
	int talla;

	lst = malloc(sizeof(t_list));
	//lst->data = NULL;
	lst->data = "Hello, world!";
	lst->next = malloc(sizeof(t_list));
	lst->next->data = "42";
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->data = NULL;
	lst->next->next->next = NULL;

	talla = ft_list_size(lst);

	printf("%d\n", talla);
	/*printf("%p\n", &lst->next->data); // data es int pero & da la address
	printf("%s\n", lst->next->data); */

	return (0);
}