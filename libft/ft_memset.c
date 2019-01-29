#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	unsigned char	ch;

	ch = (unsigned char)c;
	arr = (unsigned char *)b;
	while (len)
	{
		*arr = ch;
		arr++;
		len--;
	}
	return (b);
}
