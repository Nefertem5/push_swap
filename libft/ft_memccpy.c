#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	ch = (unsigned char)c;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n)
	{
		*p_dst = *p_src;
		if (*p_src == ch)
			return (++p_dst);
		n--;
		p_src++;
		p_dst++;
	}
	return (NULL);
}
