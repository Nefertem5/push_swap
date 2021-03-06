#include "checker.h"

void	stack_print(t_stack stack, char s)
{
	int		i;

	i = 0;
	ft_putstr("Size:");
	ft_putnbr(stack.size);
	ft_putstr(" | Stack_");
	ft_putchar(s);
	ft_putstr(": [");
	while (i < stack.size)
	{
		ft_putnbr(stack.nums[i]);
		if (i + 1 != stack.size)
			ft_putstr(", ");
		i++;
	}
	ft_putchar(']');
	ft_putchar('\n');
}

void	stacks_print(t_stack stack_a, t_stack stack_b)
{
	stack_print(stack_a, 'a');
	stack_print(stack_b, 'b');
}

void	error_ex(char **argvs)
{
	if (argvs)
		ft_del_tab(argvs);
	ft_putstr("Error\n");
	exit(1);
}

int     check_len(char **av)
{
	int	i;

	i = 0;
	while(av[i])
	{
		i++;
	}
	return (i);
}

void    ft_del_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}
