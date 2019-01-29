#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (len)
	{
		if (*src)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		len--;
		dst++;
	}
	return (ptr);
}
