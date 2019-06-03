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

void			swap(t_stack *stack);
void			push(t_stack *fir_stack, t_stack *sec_stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
t_stack			create_stack_b(int argc, char const **argv, int flag);
t_stack			create_stack_a(int argc, char const **argv, int flag);
int				is_sorted(t_stack *head);
int				check_valid(int argc, char const **argv);
void			stacks_print(t_stack stack_a, t_stack stack_b);
void			error(t_stack *a, t_stack *b, char *str);
void			swap_inner(t_stack *a, t_stack *b, char *str);
void			push_inner(t_stack *a, t_stack *b, char *str);
void			rotate_inner(t_stack *a, t_stack *b, char *str);
void			reverse_rotate_inner(t_stack *a, t_stack *b, char *str);
int				check_len(char **av);
void			error_ex();
void			stacks_print(t_stack stack_a, t_stack stack_b);
void			stack_print(t_stack stack);
void			ft_del_tab(char **tab);

#endif