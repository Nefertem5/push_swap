#include <checker.h>

void	error(t_stack *a, t_stack *b, char *str)
{
	(void) str;
	(void) a;
	(void) b;
	ft_putstr_fd("Error\n", 2);
}

void	swap_inner(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp("sa", str))
		swap(a);
	if (!ft_strcmp("sb", str))
		swap(b);
	if (!ft_strcmp("ss", str))
	{
		swap(a);
		swap(b);
	}
}

void	push_inner(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp("pa", str))
		push(b, a);
	if (!ft_strcmp("pb", str))
		push(a, b);
}

void	rotate_inner(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp("ra", str))
		rotate(a);
	if (!ft_strcmp("rb", str))
		rotate(b);
	if (!ft_strcmp("rr", str))
	{
		rotate(a);
		rotate(b);
	}
}

void	reverse_rotate_inner(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp("rra", str))
		reverse_rotate(a);
	if (!ft_strcmp("rrb", str))
		reverse_rotate(b);
	if (!ft_strcmp("rrr", str))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
