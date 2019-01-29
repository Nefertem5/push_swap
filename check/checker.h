#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int			size;
	int			*nums;
}				t_stack;

void	swap(t_stack *stack);
void	push(t_stack *fir_stack, t_stack *sec_stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
t_stack	create_stack_b(int argc, char const **argv);
t_stack	create_stack_a(int argc, char const **argv);
int		is_sorted(t_stack *head);
int		check_valid(int argc, char const **argv);

void	error(t_stack *a, t_stack *b, char *str);
void	swap_inner(t_stack *a, t_stack *b, char *str);
void	push_inner(t_stack *a, t_stack *b, char *str);
void	rotate_inner(t_stack *a, t_stack *b, char *str);
void	reverse_rotate_inner(t_stack *a, t_stack *b, char *str);

#endif