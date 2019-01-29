void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s && f)
		{
			f(&(*s));
			s++;
		}
	}
}
