#include "libft.h"

unsigned long long	handle_size_hex(va_list list, t_specifier spec)
{
	unsigned long long	size;

	if (spec.size == L)
		size = va_arg(list, unsigned long);
	else if (spec.size == LL)
		size = va_arg(list, unsigned long long);
	else
		size = va_arg(list, unsigned int);
	if (spec.size == HH)
		size = (unsigned char)size;
	else if (spec.size == H)
		size = (unsigned short)size;
	return (size);
}

void				xtoa(unsigned long long a, const char *dig, int i, char *str)
{
	while (i--)
	{
		str[i] = dig[a % 16];
		a /= 16;
	}
}

char				*hextoa(unsigned long long a, t_specifier spec)
{
	char	*str;
	char	*adress;
	int		len;
	int 	len_cage;
	int		nmbr_zeros;
	int		accur;
	int		base;

	base = (spec.specifier == 'o') ? 8 : 16;
	len = digit_len(a, base);
	accur = 0;
	if (spec.specifier != 'o')
		len_cage = ((spec.flags->cage == 1) ? 2 : 0);
	else
		len_cage = ((spec.flags->cage == 1) ? 1 : 0);
	if (spec.accur > len)
		accur = spec.accur;
	nmbr_zeros = 0;
	if (accur > len)
		nmbr_zeros = accur - len;
	else if (spec.flags->zero == 1 && spec.width > len)
		nmbr_zeros = spec.width - len - len_cage;
	if (spec.accur < len && spec.accur >= 0)
		nmbr_zeros = 0;
	len += nmbr_zeros;
	if (spec.specifier == 'o' && spec.accur > 0 && spec.flags->cage == 1)
		len -= 1;
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	if (spec.specifier == 'o')
	{
		while (len - 1 >= 0)
		{
			str[len - 1] = a % 8 + '0';
			a /= 8;
			len--;
		}
	}
	else
		xtoa(a, (spec.specifier == 'X' ? "0123456789ABCDEF" :
				"0123456789abcdef"), len, str);
	if (spec.flags->cage == 1)
	{
		if (spec.specifier == 'o')
			adress = ft_strjoin("0", str);
		else if (spec.specifier == 'X')
			adress = ft_strjoin("0X", str);
		else if (spec.specifier == 'x')
			adress = ft_strjoin("0x", str);
		free(str);
		return (adress);
	}
	return (str);
}

int					check_zero(t_specifier spec)
{
	int result;

	result = 0;
	if (spec.specifier != 'o' && spec.accur == 0)
	{
		result += write_repeat_int(' ', spec.width);
		return(result);
	}
	else if (spec.accur == -1)
	{
		if (spec.flags->minus != 1)
		{	
			if (spec.flags->zero == 1)
				result += write_repeat_int('0', spec.width - 1);
			else
				result += write_repeat_int(' ', spec.width - 1);
		}
		result += write_int('0');
		if (spec.flags->minus == 1)
			result += write_repeat_int(' ', spec.width - 1);
		return (result);
	}
	else if (spec.specifier != 'o')
	{
		if (spec.flags->minus != 1)
			result += write_repeat_int(' ', spec.width - spec.accur);
		result += write_repeat_int('0', spec.accur);
		if (spec.flags->minus == 1)
			result += write_repeat_int(' ', spec.width - spec.accur);
		return(result);
	}
	else if (spec.specifier == 'o' && spec.accur == 0)
	{
		if (spec.flags->minus != 1)
			result += write_repeat_int(' ', spec.width - spec.flags->cage);
		if (spec.flags->cage == 1)	
			result += write_int('0');
		if (spec.flags->minus == 1)
			result += write_repeat_int(' ', spec.width - spec.flags->cage);
		return(result);
	}
	else if (spec.specifier == 'o' && spec.accur > 0)
	{
		if (spec.flags->minus != 1)
			result += write_repeat_int(' ', spec.width - spec.accur);
		result += write_repeat_int('0', spec.accur);
		if (spec.flags->minus == 1)
			result += write_repeat_int(' ', spec.width - spec.accur);
		return(result);
	}
	return (result);
}

int					handle_hex(va_list list, t_specifier spec)
{
	int						result;
	int						i;
	int						accur;
	unsigned long long		number;
	char					*str;

	result = 0;
	i = 0;
	number = handle_size_hex(list, spec);
	if (number == 0)
	{	
		result += check_zero(spec);
		return (result);
	}
	if (spec.accur > 0 && spec.flags->zero == 1)
		spec.flags->zero = 0;
	str = hextoa(number, spec);
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
