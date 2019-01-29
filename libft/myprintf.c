#include "libft.h"

t_specifier	*create_specifier(char *fmt, int *i)
{
	t_specifier	*sp;

	if (!(sp = (t_specifier *)malloc(sizeof(t_specifier))))
		handle_error(0, NULL);
	sp->flags = get_flags(fmt, i);
	sp->width = 0;
	sp->accur = 0;
	sp->width = get_width(fmt, i);
	sp->accur = get_accur(fmt, i);
	get_sizemodifier(fmt, i, sp);
	get_spec(fmt, i, sp);
	if (!sp->flags)
		handle_error(0, &sp);
	return (convert_big(sp));
}

int			check_spec(va_list list, int *i, char *fmt)
{
	t_specifier	*sp;
	int			result;

	result = 0;
	if (fmt[*i] && fmt[*i] == '%')
	{
		result += write_int('%');
		(*i)++;
		return (result);
	}
	if (!(fmt[*i]))
		return (result);
	sp = create_specifier(fmt, i);
	if (!is_valid_spec(&sp, i))
	{
		spec_del(&sp);
		return (result);
	}
	result += ft_convert(*sp, list);
	return (result);
}

int			ft_printf1(va_list list, char *format)
{
	int	i;
	int	result;
	int	count;

	i = 0;
	result = 0;
	while (format[i])
	{
		count = 0;
		if (format[i] != '%')
		{
			while (format[i] && format[i] != '%')
			{
				count += write_int(format[i]);
				i++;
			}
		}
		else
		{
			i++;	
			count += check_spec(list, &i, format);
		}
		result += count;
	}
	return (result);
}

int			ft_printf(char *format, ...)
{
	va_list		list;
	int			print;

	va_start(list, format);
	print = ft_printf1(list, format);
	va_end(list);
	return (print);
}
