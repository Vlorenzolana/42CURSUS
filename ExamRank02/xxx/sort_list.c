#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *temp;
    t_list *start;
    int swap;

    //Save the pointer pointing to head of list
    start = lst;
    while(lst->next)
    {
        temp = start;
        while(temp->next)
        {
            if((cmp)(temp->data, temp->next->data) > 0)
            {
                swap = temp->data;
                temp->data = temp->next->data;
                temp->next->data = swap;
            }
            temp = temp->next;
        }
        lst = lst->next;
    }
    return (start);
}