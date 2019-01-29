#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	if (needle == haystack)
		return ((char *)haystack);
	i = 0;
	while (*haystack)
	{
		while (haystack[i] == needle[i] && haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
