#include <push_swap.h>

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
	t_stack		a;
	t_stack		b;
	int			flag;
	char		**argvs;

	flag = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2 && (flag = 1))
		argvs = ft_strsplit(argv[1], ' ');
	if (flag == 1 && !check_valid(check_len(argvs), (const char**)argvs, flag))
	{
		ft_putstr("Error\n");
		ft_del_tab(argvs);
		exit(1);
	}
	if (flag == 0 && !check_valid(argc, argv, flag))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	if (flag == 0)
	{
		a = create_stack_a(argc - 1, argv, flag);
		b = create_stack_b(argc - 1, argv, flag);
	}
	else
	{
		a = create_stack_a(check_len(argvs), (const char **)argvs, flag);
		b = create_stack_b(check_len(argvs),  (const char **)argvs, flag);
	}
	sort_stacks(a, b);
	free(a.nums);
	free(b.nums);
	if (flag == 1)
		ft_del_tab(argvs);
	return (0);
}
