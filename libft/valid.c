#include "libft.h"

int is_flag(char c)
{
	return (ft_strchr("-+ #0", c) != NULL);
}

int is_width(char c)
{
	return (ft_strchr("$*.", c) != NULL);
}

int is_type(char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

int is_size(char c)
{
	return (ft_strchr("lhL", c) != NULL);
}

int is_ok(char c)
{
	return (is_size(c) || is_type(c) || is_width(c) || is_flag(c));
}
