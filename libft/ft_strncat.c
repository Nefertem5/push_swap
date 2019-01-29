#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*start_s1;

	start_s1 = s1;
	while (*s1)
		s1++;
	while (n && *s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = '\0';
	return (start_s1);
}
