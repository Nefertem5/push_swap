#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*start;
	char		ch;

	start = s;
	ch = (char)c;
	while (*s)
		s++;
	while (s != start)
	{
		if (ch == *s)
			return ((char *)s);
		s--;
	}
	if (*start == ch)
		return ((char *)s);
	return (NULL);
}
