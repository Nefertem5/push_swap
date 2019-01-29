#include <push_swap.h>

t_stack	create_stack_b(int argc, char const **argv)
{
	t_stack	stack;
	int		i;
	int		*nums;

	i = 0;
	stack.size = 0;
	stack.nums = (int*)malloc(sizeof(int) * argc);
	nums = stack.nums;
	while (i < argc + 1)
	{
		i++;
		while (argv[i])
		{
			*nums = 0;
			nums++;
			i++;
		}
	}
	return (stack);
}

t_stack	create_stack_a(int argc, char const **argv)
{
	t_stack	stack;
	int		i;
	int		*nums;

	i = 0;
	stack.size = argc;
	stack.nums = (int*)malloc(sizeof(int) * argc);
	nums = stack.nums;
	while (i < argc + 1)
	{
		i++;
		while (argv[i])
		{
			*nums = ft_atoi(argv[i]);
			nums++;
			i++;
		}
	}
	return (stack);
}
