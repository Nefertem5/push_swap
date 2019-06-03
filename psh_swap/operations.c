#include "push_swap.h"

void	swap(t_stack stack)
{
	int	tmp;

	if (stack.size <= 1)
		return ;
	tmp = stack.nums[0];
	stack.nums[0] = stack.nums[1];
	stack.nums[1] = tmp;
}

void	push(t_stack *fir_stack, t_stack *sec_stack)
{
	int	tmp;
	int	i;

	if (fir_stack->size == 0)
		return ;
	i = 0;
	tmp = fir_stack->nums[i];
	while (i < fir_stack->size)
	{
		fir_stack->nums[i] = fir_stack->nums[i + 1];
		i++;
	}
	sec_stack->size += 1;
	fir_stack->size -= 1;
	i = sec_stack->size;
	while (0 < i)
	{
		sec_stack->nums[i] = sec_stack->nums[i - 1];
		i--;
	}
	sec_stack->nums[0] = tmp;
}

void	rotate(t_stack stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack.nums[i];
	while (i < stack.size)
	{
		stack.nums[i] = stack.nums[i + 1];
		i++;
	}
	stack.nums[stack.size - 1] = tmp;
}

void	reverse_rotate(t_stack stack)
{
	int	tmp;
	int	i;

	i = stack.size;;
	tmp = stack.nums[i - 1];
	while (0 < i)
	{
		stack.nums[i - 1] = stack.nums[i - 2];
		i--;
	}
	stack.nums[0] = tmp;
}
