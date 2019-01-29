#include "libft.h"

t_list	*ft_lstrev(t_list *list)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	next = NULL;
	prev = NULL;
	curr = list;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return (prev);
}
