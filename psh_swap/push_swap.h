#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int			size;
	int			*nums;
}				t_stack;

int				is_sorted(t_stack *stack);
int				check_valid(int argc, char const **argv, int flag);
t_stack			create_stack_a(int argc, char const **argv, int flag);
t_stack			create_stack_b(int argc, char const **argv, int flag);
void			sort_stacks(t_stack stack_a, t_stack stack_b);
void			swap(t_stack stack);
void			push(t_stack *fir_stack, t_stack *sec_stack);
void			rotate(t_stack stack);
void			reverse_rotate(t_stack stack);
void			print_swap(t_stack a, t_stack b, char name);
void			print_push(t_stack *a, t_stack *b, char name);
void			print_rotate(t_stack *a, t_stack *b, char name);
void			print_revrotate(t_stack *a, t_stack *b, char name);
void			stack_print(t_stack stack);
int				check_len(char **av);
void			ft_del_tab(char **tab);
int				ft_min3(int a, int b, int c);
int				get_index(t_stack *a, int n);
int				get_max(t_stack *s);
int				get_min(t_stack *s);
void			error_ex(char **argvs);
t_stack			create_stacks(t_stack *b, int argc, char const **argv, int flag);

#endif