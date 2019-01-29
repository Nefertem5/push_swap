#include <push_swap.h>

int		find_small(t_stack stack, int *a)
{
	int i;

	i = 1;
	*a = stack.nums[0];
	while (i < stack.size)
	{
		if ((stack.nums)[i] < *a)
			*a = (stack.nums)[i];
		i++;
	}
	i = 0;
	while ((stack.nums)[i] != *a)
		i++;
	return (i);
}

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
