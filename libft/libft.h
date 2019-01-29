#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 40
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct	s_flags
{
	int plus:2;
	int minus:2;
	int zero:2;
	int space:2;
	int cage:2;
}				t_flags;

typedef enum 	s_size_modifier
{
	L = 1,
	HH = 2,
	H = 3,
	LL = 4,
	LLL = 5,
	NO = 0
}				t_size_modifier;

typedef struct	s_specifier
{
	t_flags				*flags;
	int					width;
	int					accur;
	t_size_modifier		size;
	char				specifier;
	char				big_specifier;
}				t_specifier;

typedef struct s_convert
{
	char	specifier;
	int		(*f)(va_list, t_specifier);
}				t_convert;

int					get_accur(char *fmt, int *i);
int					get_width(char *fmt, int *i);
void				get_sizemodifier(char *fmt, int *i, t_specifier *spec);
void				get_spec(char *str, int *i, t_specifier	*sp);
t_flags				*get_flags(char *spec, int *i);
int					ft_convert(t_specifier spec, va_list list);
t_specifier			*convert_big(t_specifier *spec);
int					handle_big(va_list list, t_specifier spec);
int					write_int(char c);
int					write_repeat_int(char c, int len);
int					handle_char(va_list list, t_specifier spec);
int					handle_str(va_list list, t_specifier spec);
unsigned long long	handle_size_hex(va_list list, t_specifier spec);
void				xtoa(unsigned long long a, const char *dig, int i, char *str);
char				*hextoa(unsigned long long a, t_specifier spec);
int					check_zero(t_specifier spec);
int					handle_u(va_list list, t_specifier spec);
int					handle_hex(va_list list, t_specifier spec);
int					handle_u(va_list list, t_specifier spec);
char				*make_pointer(unsigned long int	a, t_specifier spec, char sign);
int					handle_pointer(va_list list, t_specifier spec);
char				*utiltoa_u(unsigned long long a, char sign, t_specifier spec);
int					digit_len(unsigned long long a, int base);
char				*utiltoa(long long a, char sign, t_specifier spec);
int					handle_int(va_list list, t_specifier spec);
long long			handle_size(va_list list, t_specifier spec);
void				int_to_str(int number, char *str, int len);
char				*utilftoa(long double number, t_specifier spec, char sign);
int					handle_float(va_list list, t_specifier spec);
long long			ft_pow(long long base, long long power);
t_specifier			*create_specifier(char *fmt, int *i);
int					check_spec(va_list list, int *counter, char *fmt);
int					ft_printf1(va_list list, char *format);
int					ft_printf(char *format, ...);
int					is_valid_spec(t_specifier **sp, int	*done);
void				handle_error(int code, t_specifier **sp);
void				flag_undefined(char flag, char spec);
void				spec_del(t_specifier **sp);
int					ft_atoi_i(const char *str, int *result, int *i);
int					is_flag(char c);
int					is_width(char c);
int					is_size(char c);
int					is_type(char c);
int					is_ok(char c);

int					get_next_line(const int fd, char **line);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,\
					size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *list);
t_list				*ft_lstrev(t_list *list);
#endif
