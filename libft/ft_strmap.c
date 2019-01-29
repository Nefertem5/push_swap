#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*start;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	start = new;
	while (*s && f)
	{
		*new = f(*s);
		new++;
		s++;
	}
	*new = '\0';
	return (start);
}
