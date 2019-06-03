#include "push_swap.h"

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
		error_ex(argvs);
	if (flag == 0 && !check_valid(argc, argv, flag))
		error_ex(NULL);
	if (flag == 0)
		a = create_stacks(&b, argc - 1, argv, flag);
	else
		a = create_stacks(&b, check_len(argvs), (const char **)argvs, flag);
	sort_stacks(a, b);
	return (to_return(a.nums, b.nums, flag, argvs));
}
