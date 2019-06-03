#include "push_swap.h"

int		ft_min3(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	ft_del_tab(char **tab)
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

int		check_len(char **av)
{
	int	i;

	i = 0;
	while(av[i])
	{
		i++;
	}
	return (i);
}

int		get_index(t_stack *a, int n)
{
	int	i;
	int	*arr;

	arr = a->nums;
	i = 0;
	while (i < a->size)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int		get_max(t_stack *s)
{
	int	*i;
	int	j;
	int	max;

	i = s->nums;
	j = 0;
	max = i[j];
	while (j < s->size)
	{
		if (i[j] > max)
			max = i[j];
		j++;
	}
	return (max);
}
