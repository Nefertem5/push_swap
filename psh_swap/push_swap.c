#include <push_swap.h>

void	stack_print(t_stack stack)
{
	int		i;

	i = 0;
	ft_putstr("Size:");
	ft_putnbr(stack.size);
	ft_putchar('|');
	while (i < 5)
	{
		ft_putnbr(stack.nums[i]);
		ft_putchar('|');
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char const *argv[])
{
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		exit(0);
	if (!check_valid(argc, argv))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	a = create_stack_a(argc - 1, argv);
	b = create_stack_b(argc - 1, argv);
	sort_stacks(a, b);
}
