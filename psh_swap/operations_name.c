#include "push_swap.h"

void	print_swap(t_stack a, t_stack b, char name)
{
	if (name == 'a')
	{
		swap(a);
		ft_printf("s%c\n", name);
	}
	if (name == 'b')
	{
		swap(b);
		ft_printf("s%c\n", name);
	}
	if (name == 's')
	{
		swap(a);
		swap(b);
		ft_printf("s%c\n", name);
	}
}

void	print_push(t_stack *a, t_stack *b, char name)
{
	if (name == 'a')
	{
		push(b, a);
		ft_printf("p%c\n", name);
	}
	if (name == 'b')
	{
		push(a, b);
		ft_printf("p%c\n", name);
	}
}

void	print_rotate(t_stack *a, t_stack *b, char name)
{
	if (name == 'a')
	{
		rotate(*a);
		ft_printf("r%c\n", name);
	}
	if (name == 'b')
	{
		rotate(*b);
		ft_printf("r%c\n", name);
	}
	if (name == 'r')
	{
		rotate(*a);
		rotate(*b);
		ft_printf("r%c\n", name);
	}
}

void	print_revrotate(t_stack *a, t_stack *b, char name)
{
	if (name == 'a')
	{
		reverse_rotate(*a);
		ft_printf("rr%c\n", name);
	}
	if (name == 'b')
	{
		reverse_rotate(*b);
		ft_printf("rr%c\n", name);
	}
	if (name == 'r')
	{
		reverse_rotate(*a);
		reverse_rotate(*b);
		ft_printf("rr%c\n", name);
	}
}
