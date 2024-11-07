#include "list.h"
#include <stdio.h>
#include <unistd.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *start;
	int swap;

	start = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return start;
}
