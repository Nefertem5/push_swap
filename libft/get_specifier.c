#include "libft.h"

t_flags		*get_flags(char *spec, int *i)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->cage = 0;
	flags->minus = 0;
	while ((spec[*i] == ' ' || spec[*i] == '-' || spec[*i] == '0'
			|| spec[*i] == '+' || spec[*i] == '#') && spec[*i])
	{
		if (spec[*i] == ' ')
			flags->space = 1;
		else if (spec[*i] == '-')
			flags->minus = 1;
		else if (spec[*i] == '+')
			flags->plus = 1;
		else if (spec[*i] == '0')
			flags->zero = 1;
		else if (spec[*i] == '#')
			flags->cage = 1;
		(*i)++;
	}
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	return (flags);
}

int			get_width(char *fmt, int *i)
{
	int	width;

	width = 0;
	if (!ft_isdigit(fmt[*i]))
		return (-1);
	ft_atoi_i(fmt, &width, i);
	while (ft_isdigit(fmt[*i]) && fmt[*i])
		(*i)++;
	return (width);
}

int			get_accur(char *fmt, int *i)
{
	int	accur;

	accur = 0;
	if (fmt[*i] == '.')
	{
		(*i)++;
		ft_atoi_i(fmt, &accur, i);
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		return (accur);
	}
	return (-1);
}

void		get_sizemodifier(char *fmt, int *i, t_specifier *spec)
{
	t_size_modifier	size;

	size = NO;
	if (!is_size(fmt[*i]))
		return ;
	if (fmt[*i] == 'l')
	{
		if (fmt[*i + 1] == 'l' && ++(*i))
			size = LL;
		else
			size = L;
	}
	else if (fmt[*i] == 'h')
	{
		if (fmt[*i + 1] == 'h' && ++(*i))
			size = HH;
		else
			size = H;
	}
	else if (fmt[*i] == 'L')
		size = LLL;
	spec->size = size;
	(*i)++;
}

void		get_spec(char *str, int *i, t_specifier	*sp)
{
	int			result;

	result = 0;
	if (ft_strchr("ABCDEGHIJKLMNOPQRTUVWYZ", str[*i]))
	{
		sp->big_specifier = (int)str[*i];
		result = 'D';
		(*i)++;
	}
	else if (is_type(str[*i]))
	{
		result = (int)str[*i];
		(*i)++;
	}
	sp->specifier = result;
}
