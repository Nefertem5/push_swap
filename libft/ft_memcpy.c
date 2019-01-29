#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		*ptr_dst = *ptr_src;
		n--;
		ptr_dst++;
		ptr_src++;
	}
	return (dst);
}
