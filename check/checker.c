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

void	exec_ops(t_stack *a, t_stack *b)
{
	char	*line;
	void	(*f[5])();

	init_funcs(f);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp("", line))
		{
			free(line);
			break;
		}
		f[get_ops_code(line)](a, b, line);
		if (!get_ops_code(line))
		{
			free(line);
			exit(0);
		}
		free(line);
	}
	if (is_sorted(a) && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		exit(0);
	if (!check_valid(argc, argv))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	a = create_stack_a(argc - 1, argv);
	b = create_stack_b(argc - 1, argv);
	exec_ops(&a, &b);
	return (0);
}
