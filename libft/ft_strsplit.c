#include "libft.h"
#include <stdlib.h>

static	unsigned int	ft_count_str(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void				ft_free_trash(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	char			*ft_create_word(char const **s, char c, char **tab)
{
	char			*str;
	unsigned int	len;

	len = 0;
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		ft_free_trash(tab);
		return (NULL);
	}
	ft_strncpy(str, *s - len, len);
	str[len] = '\0';
	return (str);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int	count_words;
	unsigned int	i;
	char			**tab;
	char			*word;

	if (!s)
		return (NULL);
	count_words = ft_count_str(s, c);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!(*s))
			break ;
		if (!(word = ft_create_word(&s, c, tab)))
			return (NULL);
		tab[i++] = word;
		while (*s != c && *s)
			s++;
	}
	tab[count_words] = NULL;
	return (tab);
}
