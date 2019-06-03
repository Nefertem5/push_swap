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

int		main(int argc, char const **argv)
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
