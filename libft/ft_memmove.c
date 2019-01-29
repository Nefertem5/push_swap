#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst > ptr_src)
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	else if (ptr_dst != ptr_src)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	return (dst);
}
