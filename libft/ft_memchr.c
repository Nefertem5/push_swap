#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	ch;

	arr = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n)
	{
		if (*arr == ch)
			return (arr);
		n--;
		arr++;
	}
	return (NULL);
}
