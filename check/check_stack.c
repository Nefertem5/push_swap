#include "checker.h"

int		is_sorted(t_stack *stack)
{
	int	current;
	int	prev;
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		current = stack->nums[i];
		prev = stack->nums[i + 1];
		if (prev < current)
			return (0);
		i++;
	}
	return (1);
}
