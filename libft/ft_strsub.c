
#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*start_sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	start_sub = sub;
	while (len)
	{
		*sub = s[start];
		start++;
		len--;
		sub++;
	}
	*sub = '\0';
	return (start_sub);
}
