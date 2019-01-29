#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	dst_len = (size_t)ft_strlen(dst);
	src_len = (size_t)ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst)
		dst++;
	while (size - dst_len - 1 > 0)
	{
		if (*src)
		{
			*dst = *src;
			src++;
			dst++;
		}
		else
		{
			*dst = '\0';
		}
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
