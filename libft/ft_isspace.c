#include "libft.h"

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v'
			|| c == '\f');
}
