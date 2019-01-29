#include "libft.h"

void	spec_del(t_specifier **sp)
{
	if ((*sp)->flags)
		free((*sp)->flags);
	free(*sp);
	*sp = NULL;
}

void	flag_undefined(char flag, char spec)
{
	ft_putstr("warning: flag '");
	ft_putchar(flag);
	ft_putstr("' results in undefined behavior with '");
	ft_putchar(spec);
	ft_putstr("'\n");
}

void	handle_error(int code, t_specifier **sp)
{
	if (code == 0)
	{
		ft_putstr("error: insufficient memory space available\n");
		if (sp)
		spec_del(sp);
		exit(0);
	}
	else if (code == 1)
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar((*sp)->specifier);
		ft_putstr("'\n");
	}
	else if (code == 2 || code == 3)
		flag_undefined(code == 2 ? '#' : '0', (*sp)->specifier);
	else if (code == 4)
		ft_putstr("warning: flag '0' is ignored when flag '-' is present\n");
	else if (code == 5)
		ft_putstr("warning: flag ' ' is ignored when flag '+' is present\n");
}

int		is_valid_spec(t_specifier **sp, int	*done)
{
	if (!*sp)
		handle_error(0, NULL);
	if (!ft_strchr("dDiouxXsScCpfFbrkge%", (*sp)->specifier))
	{
		ft_putchar((*sp)->specifier);
		(*done)++;
		return (0);
	}
	return (1);
}

int		ft_atoi_i(const char *str, int *result, int *i)
{
	int nbr;
	int neg;

	neg = (str[*i] == '-');
	if (str[*i] == '-' || str[*i] == '+')
			return (1);
	nbr = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = nbr * 10 + (str[*i] - '0');
		(*i)++;
	}
	*result = (neg ? -nbr : nbr);
	return (0);
}
