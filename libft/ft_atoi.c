#include "libft.h"

int		ft_atoi(const char *str)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		if ((*str - '0') * 10 > 9223372036854775807 - result)
			return (sign == -1 ? 0 : -1);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * (int)result);
}
