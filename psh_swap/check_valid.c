#include <push_swap.h>

long long		ft_atoll(const char *str)
{
	long long int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str && ft_isdigit(*str))
	{
		if ((*str - '0') * 10 > 9223372036854775807 - ret)
			return (sign == -1 ? 0 : -1);
		ret = ret * 10 + (*str - '0');
		++str;
	}
	return (sign * ret);
}

static int		is_valid_arg(const char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg) && *arg != '-')
			return (0);
		arg++;
	}
	return (1);
}

static int		check_duplicates(long long *arr, int siz)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (i < siz)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
				return (0);
		j = 0;
		counter = 0;
		while (j < siz)
		{
			if (arr[i] == arr[j])
				counter++;
			j++;
		}
		if (counter > 1)
			return (0);
		i++;
	}
	return (1);
}

int				check_valid(int argc, char const **argv)
{
	long long	arr[argc - 1];
	int			i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_arg(argv[i]))
			return (0);
		arr[i - 1] = ft_atoll(argv[i]);
		i++;
	}
	if (!check_duplicates(arr, argc - 1))
		return (0);
	return (1);
}
