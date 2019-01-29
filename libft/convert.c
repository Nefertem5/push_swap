#include "libft.h"

t_specifier	*convert_big(t_specifier *spec)
{
	if (spec->specifier == 'S')
		spec->size = L;
	if (spec->specifier == 'S')
		spec->specifier = 's';
	return (spec);
}

int			handle_big(va_list list, t_specifier spec)
{
	int		result;
	char	*str;
	int		i;

	result = 0;
	(void)list;
	result += write_int('%');
	if (spec.specifier == '%')
		return (result);
	if (spec.flags->cage == 1)
		result += write_int('#');
	if (spec.flags->plus == 1)
		result += write_int('+');
	if (spec.flags->minus == 1)
		result += write_int('-');
	if (spec.flags->minus != 1 && spec.flags->plus != 1 && spec.flags->space == 1)
		result += write_int(' ');
	if (spec.flags->zero == 1)
		result += write_int('0');
	if (spec.width > 0)
	{
		str = ft_itoa(spec.width);
		i = 0;
		while (str[i] != '\0')
		{
			result += write_int(str[i]);
			i++;
		}
		free(str);
	}
	if (spec.accur != -1)
	{
		result += write_int('.');
		str = ft_itoa(spec.accur);
		i = 0;
		while (str[i] != '\0')
		{
			result += write_int(str[i]);
			i++;
		}
		free(str);
	}
	result += write_int(spec.big_specifier);
	return (result);
}

int			ft_convert(t_specifier spec, va_list list)
{
	int	i;
	static t_convert	(convert[12]) = {
		{ .specifier = 's', .f = handle_str },
		{ .specifier = 'c', .f = handle_char },
        { .specifier = 'd', .f = handle_int },
        { .specifier = 'D', .f = handle_big },
        { .specifier = '%', .f = handle_big },
        { .specifier = 'i', .f = handle_int },
		{ .specifier = 'x', .f = handle_hex },
		{ .specifier = 'X', .f = handle_hex },
		{ .specifier = 'p', .f = handle_pointer },
		{ .specifier = 'u', .f = handle_u },
		{ .specifier = 'o', .f = handle_hex },
		{ .specifier = 'f', .f = handle_float }
	};

	i = -1;
	while (++i < 12)
	{
		if (spec.specifier == convert[i].specifier)
			return(convert[i].f(list, spec));
	}
	return (0);
}
