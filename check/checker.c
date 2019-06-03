#include <checker.h>

int		get_ops_code(char *line)
{
	if (!ft_strcmp("pa", line))
		return (1);
	else if (!ft_strcmp("pb", line))
		return (1);
	else if (!ft_strcmp("ra", line))
		return (2);
	else if (!ft_strcmp("rb", line))
		return (2);
	else if (!ft_strcmp("sa", line))
		return (3);
	else if (!ft_strcmp("sb", line))
		return (3);
	else if (!ft_strcmp("rra", line))
		return (4);
	else if (!ft_strcmp("rrb", line))
		return (4);
	else if (!ft_strcmp("ss", line))
		return (3);
	else if (!ft_strcmp("rr", line))
		return (2);
	else if (!ft_strcmp("rrr", line))
		return (4);
	else
		return (0);
}

void	init_funcs(void (*f[4])())
{
	f[0] = &error;
	f[1] = &push_inner;
	f[2] = &rotate_inner;
	f[3] = &swap_inner;
	f[4] = &reverse_rotate_inner;
}

void	exec_ops(t_stack *a, t_stack *b, int flag)
{
	char	*line;
	void	(*f[5])();

	init_funcs(f);
	while (get_next_line(0, &line) > 0)
	{
		f[get_ops_code(line)](a, b, line);
		if (!get_ops_code(line))
		{
			free(line);
			exit(0);
		}
		if (flag)
			stacks_print(*a, *b);
		free(line);
	}
	if (is_sorted(a) && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void			ft_del_tab(char **tab)
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

void	stack_print(t_stack stack)
{
	int		i;

	i = 0;
	ft_putstr("Size:");
	ft_putnbr(stack.size);
	ft_putstr(" | Stack: [");
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
	stack_print(stack_a);
	stack_print(stack_b);
}

void	error_ex()
{
	ft_putstr("Error\n");
	exit(1);
}

int	check_len(char **av)
{
	int	i;

	i = 0;
	while(av[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char const **argv)
{
	t_stack	a;
	t_stack	b;
	int		flag;
	int		v_flag;
	char	**argvs;

	flag = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2 && (flag = 1))
	{
		argvs = ft_strsplit(argv[1], ' ');
		v_flag = ft_strcmp(argvs[0], "-v") == 0;
	}
	else
		v_flag = ft_strcmp(argv[1], "-v") == 0;
	if (flag == 1 && !check_valid(argc - v_flag, (const char**)argvs + v_flag))
	{
		ft_del_tab(argvs);
		error_ex();
	}
	else if (!check_valid(argc - v_flag, argv + v_flag))
		error_ex();
	if (flag == 0)
	{
		a = create_stack_a(argc - 1 - v_flag, argv + v_flag, flag);
		b = create_stack_b(argc - 1 - v_flag, argv + v_flag, flag);
	}
	else
	{
		a = create_stack_a(check_len(argvs) - v_flag, (const char **)argvs + v_flag, flag);
		b = create_stack_b(check_len(argvs) - v_flag,  (const char **)argvs + v_flag, flag);
	}
	exec_ops(&a, &b, v_flag);
	free(a.nums);
	free(b.nums);
	if (flag == 1)
		ft_del_tab(argvs);
	return (0);
}
