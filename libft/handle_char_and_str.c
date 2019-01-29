#include "libft.h"

int			write_int(char c)
{
	return (write(1, &c, 1));
}

int			write_repeat_int(char c, int len)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < len)
	{
		result += write_int(c);
		i++;
	}
	return (result);
}

int			handle_char(va_list list, t_specifier spec)
{
	int		result;
	int		c;

	result = 0;
	c = va_arg(list, int);
	if ((spec.flags->minus != 1) && spec.width > 1)
		result += write_repeat_int(' ', spec.width - 1);
	result += write_int((char)c);
	if ((spec.flags->minus == 1) && spec.width > 1)
		result += write_repeat_int(' ', spec.width - 1);
	return (result);
}

int			handle_str(va_list list, t_specifier spec)
{
	int		result;
	int		len;
	int		accur;
	int		i;
	char	*str;

	result = 0;
	i = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (spec.accur > len)
		accur = len;
	else if (spec.accur == -1)
		accur = len;
	else
		accur = spec.accur;
	if ((spec.flags->minus != 1) && spec.width > accur)
		result += write_repeat_int(' ', spec.width - accur);
	while (str[i] != '\0' && accur > 0)
	{
			result += write_int(str[i]);
			i++;
			accur--;
	}
	if ((spec.flags->minus == 1) && spec.width > accur)
		result += write_repeat_int(' ', spec.width - accur - i);
	return (result);
}
