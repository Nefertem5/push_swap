#include "libft.h"

long long	ft_pow(long long base, long long power)
{
	long long	i;
	long long	ret;
	long long	tmp;

	i = 0;
	ret = 1;
	while (i < power && i < 19)
	{
		tmp = ret;
		ret *= base;
		if (tmp > ret)
			return (tmp);
		i++;
	}
	return (ret);
}

void		int_to_str(int number, char *str, int len)
{
	while (len--)
	{
		str[len] = number % 10 + '0'; 
		number /= 10;
	}
}

char		*utilftoa(long double number, t_specifier spec, char sign)
{
	int			intpart;
	long double	fpart;
	float		ffpart;
	int			len;
	int			accur;
	int			nmbr_zeros;
	char		*str;
	char		*fstr;
	char		*result;

	intpart = (int)number;
	fpart = number - (long double)intpart;
	if (fpart >= 0.5 && spec.accur == 0)
		intpart += 1;
	len = digit_len((long long)intpart, 10);
	nmbr_zeros = 0;
	accur = 0;
	if (spec.accur > 0)
		accur = spec.accur;
	else if (spec.accur == -1)
		accur = 6;
	if (spec.flags->zero == 1 && spec.width > len)
	{
		nmbr_zeros = spec.width - len - accur - 1;
		if (spec.flags->cage == 0 && spec.accur == 0)
			nmbr_zeros += 1;
	}
	if (nmbr_zeros > 0)
		nmbr_zeros -= (sign ? 1 : 0);
	len += nmbr_zeros + (sign ? 1 : 0);
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	int_to_str(intpart, str, len);
	if (sign != 0)
		str[0] = sign;
	if (spec.flags->cage == 0 && spec.accur == 0)
		return (str);
	if ((fstr = ft_strnew((size_t)accur + 1)) == NULL)
		return (NULL);
	len = 0;
	if (accur != 0)
	{
		fpart *= ft_pow(10, accur);
		while (fpart > 999999999)
		{
			fpart /= 10;
			accur--;
			len++;
		}
		intpart = fpart;
		ffpart = fpart - (int)intpart;
		if (ffpart >= 0.5)
			fpart += 1;
		while (len--)
			fstr[len + accur + 1] = '0';
		int_to_str(fpart, fstr, accur + 1);
	}
	fstr[0] = '.';
	result = ft_strjoin(str, fstr);
	free(str);
	free(fstr);
	return (result);
}	

int			handle_float(va_list list, t_specifier spec)
{
	int			result;
	int			accur;
	int			i;
	long double	n;
	char		sign;
	char		*str;

	result = 0;
	i = 0;
	if (spec.size == L || spec.size == LLL)
		n = va_arg(list, long double);
	else
		n = va_arg(list, double);
	if (spec.flags->plus == 1)
		sign = '+';
	else if (spec.flags->space == 1)
		sign = ' ';
	else
		sign = 0;
	if (n < 0)
	{
		sign = '-';
		n *= -1;
	}
	str = utilftoa(n, spec, sign);
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
