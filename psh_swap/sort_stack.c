#include <push_swap.h>

void	sort_three(t_stack *a, t_stack *b)
{
	int	*tmp;

	tmp = a->nums;
	if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] < tmp[2])
	{
		print_rotate(*a, *b, 'a');
		print_swap(*a, *b, 'a');
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		print_revrotate(*a, *b, 'a');
		print_swap(*a, *b, 'a');
	}
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2])
		print_rotate(*a, *b, 'a');
	while (!is_sorted(a))
	{
		print_swap(*a, *b, 'a');
		sort_three(a, b);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int i;

	i = 0;
	while (stack_a->size > 1)
	{
		i = find_small(*stack_a, &a);
		if (stack_a->nums[0] == a)
			print_push(stack_a, stack_b, 'b');
		else if (stack_a->size / 2 >= i)
			print_rotate(*stack_a, *stack_b, 'a');
		else
			print_revrotate(*stack_a, *stack_b, 'a');
	}
	while (stack_b->size > 0)
		print_push(stack_a, stack_b, 'a');
}

void	sort_stacks(t_stack stack_a, t_stack stack_b)
{
	int		*tmp;

	tmp = stack_a.nums;
	if (stack_a.size == 2 && !is_sorted(&stack_a))
		print_swap(stack_a, stack_b, 'a');
	else if (stack_a.size == 3)
		sort_three(&stack_a, &stack_b);
	else if (tmp[0] > tmp[1])
		print_swap(stack_a, stack_b, 'a');
	else if (tmp[stack_a.size - 1] < tmp[stack_a.size - 2])
	{
		print_revrotate(stack_a, stack_b, 'a');
		print_revrotate(stack_a, stack_b, 'a');
		print_swap(stack_a, stack_b, 'a');
		print_rotate(stack_a, stack_b, 'a');
		print_rotate(stack_a, stack_b, 'a');
	}
	else if (stack_a.size > 2 && !is_sorted(&stack_a))
		sort(&stack_a, &stack_b);
	if (!is_sorted(&stack_a))
		sort_stacks(stack_a, stack_b);
}
