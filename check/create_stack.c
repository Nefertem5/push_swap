#include <checker.h>

t_stack	create_stack_b(int argc, char const **argv, int flag)
{
	t_stack	stack;
	int		i;
	int		*nums;

	i = 0 - flag;
	stack.size = 0;
	stack.nums = (int*)malloc(sizeof(int) * argc);
	nums = stack.nums;
	i++;
	while (i < argc + 1 && argv[i])
	{
		*nums = 0;
		nums++;
		i++;
	}
	return (stack);
}

t_stack	create_stack_a(int argc, char const **argv, int flag)
{
	t_stack	stack;
	int		i;
	int		*nums;

	i = 0 - flag;
	stack.size = argc;
	stack.nums = (int*)malloc(sizeof(int) * argc);
	nums = stack.nums;
	i++;
	while (i < argc + 1 && argv[i])
	{
		*nums = ft_atoi(argv[i]);
		nums++;
		i++;
	}
	return (stack);
}
