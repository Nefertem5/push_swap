#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
