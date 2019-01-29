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

int		find_small(t_stack stack, int *a);
int		is_sorted(t_stack *stack);
int		check_valid(int argc, char const **argv);
t_stack	create_stack_a(int argc, char const **argv);
t_stack	create_stack_b(int argc, char const **argv);
void	sort_stacks(t_stack stack_a, t_stack stack_b);
void	swap(t_stack stack);
void	push(t_stack *fir_stack, t_stack *sec_stack);
void	rotate(t_stack stack);
void	reverse_rotate(t_stack stack);
void	print_swap(t_stack a, t_stack b, char name);
void	print_push(t_stack *a, t_stack *b, char name);
void	print_rotate(t_stack a, t_stack b, char name);
void	print_revrotate(t_stack a, t_stack b, char name);

#endif