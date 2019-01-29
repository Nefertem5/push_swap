#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;
	t_list	*current;

	if (lst && f)
	{
		next = lst->next;
		current = lst;
		while (current)
		{
			next = current->next;
			f(current);
			current = next;
		}
	}
}
