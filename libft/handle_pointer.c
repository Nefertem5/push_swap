#include "libft.h"

char	*make_pointer(unsigned long int	a, t_specifier spec, char sign)
{
	char		*str;
	char		*adress;
	int			len;
	int			sign_len;
	int			accur;
	int			nmbr_zeros;
	const char	*sym;

	sym = "0123456789abcdef";
	len = digit_len(a, 16);
	accur = 0;
	if (a == 0)
	{
		str = ft_strnew(5);
		str = ft_strcpy(str, "(nil)");
		return (str);
	}
	if (spec.accur > len)
		accur = spec.accur;
	nmbr_zeros = 0;
	if (accur > len)
		nmbr_zeros = accur - len;
	else if (spec.flags->zero == 1 && spec.width > len)
		nmbr_zeros = spec.width - len - 2;
	if (spec.accur < len && spec.accur >= 0)
		nmbr_zeros = 0;
	sign_len = (sign ? 1 : 0);
	len = len + 2 + nmbr_zeros;
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	if (spec.flags->zero == 1 && sign_len)
		len--;
	while (len - 1 >= 0)
	{
		str[len - 1] = sym[a % 16];
		a /= 16;
		len--;
	}
	str[1] = 'x';
	str[0] = '0';
	if (sign_len != 0)
	{	
		if (sign == ' ')
			adress = ft_strjoin(" ", str);
		else if (sign == '+')
			adress = ft_strjoin("+", str);
	}
	else
		return (str);
	free(str);
	if (!adress)
		return (NULL);
	return (adress);
}

int		handle_pointer(va_list list, t_specifier spec)
{
	unsigned long int	p;
	int					result;
	int					accur = 0;
	int					i;
	char				*str;
	char				sign;

	result = 0;
	i = 0;
	p = (unsigned long int)va_arg(list, void *);
	if (spec.flags->plus == 1)
		sign = '+';
	else if (spec.flags->space == 1)
		sign = ' ';
	else
		sign = 0;
	str = make_pointer(p, spec, sign);
	accur = ft_strlen(str);
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

int		handle_u(va_list list, t_specifier spec)
{
	int						result;
	int						i;
	int						accur;
	unsigned long long		number;
	char					*str;

	result = 0;
	i = 0;
	number = handle_size_hex(list, spec);
	if (spec.accur == 0 && number == 0)
		return (0);
	if (spec.accur == 0 && number == 0)
		return (0);
	if (spec.accur > 0 && spec.flags->zero == 1)
		spec.flags->zero = 0;
	str = utiltoa_u(number, 0, spec);
	accur = ft_strlen(str);
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
