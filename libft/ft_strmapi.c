#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*start;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	start = new;
	index = 0;
	while (s[index] && f)
	{
		new[index] = f(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (start);
}
