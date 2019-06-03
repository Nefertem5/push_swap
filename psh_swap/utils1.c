#include "push_swap.h"

int		get_min(t_stack *s)
{
	int	i;
	int	*arr;
	int	min;

	i = 0;
	arr = s->nums;
	min = arr[i];
	while (i < s->size)
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

void	error_ex(char **argvs)
{
	if (argvs)
		ft_del_tab(argvs);
	ft_putstr("Error\n");
	exit(1);
}
