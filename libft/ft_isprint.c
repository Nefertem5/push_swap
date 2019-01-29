#include "libft.h"

int		ft_isprint(int c)
{
	if ((c >= 040 && c <= 047) || (c >= 050 && c <= 0176))
		return (1);
	return (0);
}
