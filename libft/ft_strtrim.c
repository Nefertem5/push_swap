#include "libft.h"
#include <stdlib.h>

static int	ft_inner_trim(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}

char		*ft_strtrim(char const *s)
{
	char			*newstr;
	unsigned int	start;
	unsigned int	end;
	size_t			slen;

	if (s)
	{
		start = 0;
		slen = ft_strlen(s);
		while (s[start] && ft_inner_trim(s[start]))
			++start;
		end = slen == 0 ? 0 : slen - 1;
		while (end > start && ft_inner_trim(s[end]))
			--end;
		newstr = (char *)malloc(sizeof(char) * (end - start + 2));
		if (!newstr)
			return (NULL);
		ft_strncpy(newstr, s + start, end - start + 1);
		newstr[end - start + 1] = '\0';
		return (newstr);
	}
	return (NULL);
}
