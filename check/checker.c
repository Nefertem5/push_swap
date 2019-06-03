#include <checker.h>

int		to_return(int *arr, int *arr2, int flag, char **argvs)
{
	free(arr);
	free(arr2);
	if (flag == 1)
		ft_del_tab(argvs);
	return (0);
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
	if (flag == 1 && !check_valid(check_len(argvs) - v_flag, (const char**)argvs + v_flag))
		error_ex(argvs);
	else if (!check_valid(argc - v_flag, argv + v_flag))
		error_ex(NULL);
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
	return (to_return(a.nums, b.nums, flag, argvs));
}
