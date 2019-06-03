#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	*tmp;

	tmp = a->nums;
	if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] < tmp[2])
	{
		print_rotate(a, b, 'a');
		print_swap(*a, *b, 'a');
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		print_revrotate(a, b, 'a');
		print_swap(*a, *b, 'a');
	}
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2])
		print_rotate(a, b, 'a');
	while (!is_sorted(a))
	{
		print_swap(*a, *b, 'a');
		sort_three(a, b);
	}
}

int		get_nearest_number(t_stack *stack, int num)
{
	int	dist;
	int	min_d;
	int	nearest;
	int	i;

	dist = num - stack->nums[0] > 0 ? num - stack->nums[0] : -(num - stack->nums[0]);
	min_d = 2147483647;
	nearest = stack->nums[0];
	i = 0;
	while (i < stack->size)
	{
		dist = num - stack->nums[i] > 0 ? num - stack->nums[i] : -(num - stack->nums[i]);
		if (min_d > dist)
		{
			min_d = dist;
			nearest = stack->nums[i];
		}
		i++;
	}
	return (nearest);
}

int		find_place(t_stack *s, int num)
{
	int	index;
	int	nearest;

	nearest = get_nearest_number(s, num);
	index = get_index(s, nearest);
	if (nearest < num)
		index += 1;
	return (index);
}

int		get_way_inner(t_stack *s, int index)
{
	return ((index > s->size / 2) ? s->size - index : index);
}

int		get_way_ab_inner(t_stack *a, t_stack *b, int a_index, int b_index)
{
	int	direction_a;
	int	direction_b;
	int	total_way;
	int	way_a;
	int	way_b;

	direction_a = a_index > a->size / 2;
	direction_b = b_index > b->size / 2;
	way_a = get_way_inner(a, a_index);
	way_b = get_way_inner(b, b_index);
	if (direction_a == direction_b)
		total_way = (way_a > way_b) ? way_a : way_b;
	else
		total_way = way_a + way_b;
	return (total_way);
}


int		get_way_ab(t_stack *a, t_stack *b)
{
	int		a_index;
	int		b_index;
	int		min_way;

	min_way = a->size + b->size;
	b_index = 0;
	while (b_index < b->size)
	{
		a_index = find_place(a, b->nums[b_index]);
		if (min_way > get_way_ab_inner(a, b, a_index, b_index))
			min_way = get_way_ab_inner(a, b, a_index, b_index);
		b_index++;
	}
	return (min_way);
}

int		get_way_a(t_stack *a, t_stack *b)
{
	int	index;
	int	way;

	index = find_place(a, b->nums[0]);
	if (b->nums[0] < get_min(a))
		index = get_index(a, get_min(a));
	way = index > a->size / 2 ? a->size - index : index;
	return (way);
}

void	scroll_up(t_stack *a, t_stack *b, int n, char ch)
{
	int	i;

	i = 0;
	while (i < n)
	{
		print_rotate(a, b, ch);
		i++;
	}
}

void	scroll_down(t_stack *a, t_stack *b, int n, char ch)
{
	int	i;

	i = 0;
	while (i < n)
	{
		print_revrotate(a, b, ch);
		i++;
	}
}

void	move_a_pa_inner(t_stack *a, t_stack *b, int place)
{
	if (place >= a->size / 2)
	{
		if (place > 0)
			scroll_down(a, b, a->size - place, 'a');
		if (place != 0 && place == a->size && b->nums[0] > get_max(a))
		{
			print_push(a, b, 'a');
			scroll_up(a, b, 1, 'a');
		}
		else
			print_push(a, b, 'a');
	}
	else
	{
		scroll_up(a, b, place, 'a');
		if (place != 0 && place == a->size && b->nums[0] > get_max(a))
		{
			print_push(a, b, 'a');
			scroll_up(a, b, 1, 'a');
		}
		else
			print_push(a, b, 'a');
	}
}


void	move_a_pa(t_stack *a, t_stack *b)
{
	int	place;

	place = find_place(a, b->nums[0]);
	move_a_pa_inner(a, b, place);
}

int		get_way_b(t_stack *a, t_stack *b)
{
	int	index;
	int	way;
	int	last_a;

	last_a = a->nums[a->size - 1];
	index = find_place(b, a->nums[0]);
	if (index >= b->size || b->nums[index] > a->nums[0])
		return (a->size + b->size);
	else if (b->nums[index] <  a->nums[0] && b->nums[index] < last_a)
		return (a->size + b->size);
	way = index > b->size / 2 ? b->size - index : index;
	return (way);
}

void	move_b_pa_inner(t_stack *a, t_stack *b, int place, int min)
{
	if (place >= b->size / 2)
	{
		scroll_down(a, b, b->size - place, 'b');
		print_push(a, b, 'a');
		while (b->nums[0] < a->nums[0] && b->nums[0] > min)
			print_push(a, b, 'a');
	}
	else
	{
		scroll_up(a, b, place, 'b');
		print_push(a, b, 'a');
		while (b->nums[0] < a->nums[0] && b->nums[0] > min)
			print_push(a, b, 'a');
	}
}

void	move_b_pa(t_stack *a, t_stack *b)
{
	int	place;
	int	tmp;
	int	b_num;

	place = get_index(b, get_nearest_number(b, a->nums[0]));
	place = find_place(b, a->nums[0]);
	if (a->nums[0] < get_min(b))
		place = get_index(b, get_min(b));
	b_num = b->nums[place];
	tmp = a->nums[get_index(a, get_nearest_number(a, b_num))];
	move_b_pa_inner(a, b, place, tmp);
}

void	scroll_rrr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		print_revrotate(a, b, 'r');
		i++;
	}
}

void	scroll_rr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		print_rotate(a, b, 'r');
		i++;
	}
}

void	move_ab_pa_inner(t_stack *a, t_stack *b, int a_index, int b_index)
{
	int	direction_a;
	int	direction_b;
	int	way_a;
	int	way_b;
	int	tmp;

	direction_a = a_index > a->size / 2;
	direction_b = b_index > b->size / 2;
	way_a = get_way_inner(a, a_index);
	way_b = get_way_inner(b, b_index);
	if (direction_a == direction_b)
	{
		if (direction_a == 1)
			scroll_rrr(a, b, (way_a < way_b ? way_a : way_b));
		else
			scroll_rr(a, b, (way_a < way_b ? way_a : way_b));
		tmp = way_a < way_b ? way_a : way_b;
		way_a -= tmp;
		way_b -= tmp;
	}
	if (way_a > 0)
	{
		if (direction_a == 1)
			scroll_down(a, b, way_a, 'a');
		else
			scroll_up(a, b, way_a, 'a');
	}
	if (way_b > 0)
	{
		if (direction_a == 1)
			scroll_down(a, b, way_b, 'b');
		else
			scroll_up(a, b, way_b, 'b');
	}
	print_push(a, b, 'a');
}

void	move_ab_pa(t_stack *a, t_stack *b)
{
	int		a_index;
	int		b_index;
	int		index_min[2];
	int		min_way;

	min_way = a->size + b->size;
	b_index = 0;
	while (b_index < b->size)
	{
		a_index = find_place(a, b->nums[b_index]);
		if (b->nums[b_index] < get_min(a))
			a_index = a->nums[get_min(a)];
		if (min_way > get_way_ab_inner(a, b, a_index, b_index))
		{
			min_way = get_way_ab_inner(a, b, a_index, b_index);
			index_min[1] = b_index;
			index_min[0] = a_index;
		}
		b_index++;
	}
	move_ab_pa_inner(a, b, index_min[0], index_min[1]);
}

void	sort_stacks(t_stack stack_a, t_stack stack_b)
{
	int	min_index;

	while (!is_sorted(&stack_a) && stack_a.size > 3)
		print_push(&stack_a, &stack_b, 'b');
	sort_three(&stack_a, &stack_b);
	while (stack_b.size > 0)
	{
		if ((ft_min3(get_way_a((&stack_a), (&stack_b)), get_way_b((&stack_a), (&stack_b)),
			get_way_ab((&stack_a), (&stack_b)))) == get_way_a((&stack_a), (&stack_b)))
			move_a_pa(&stack_a, &stack_b);
		else if ((ft_min3(get_way_a((&stack_a), (&stack_b)), get_way_b((&stack_a), (&stack_b)),
			get_way_ab((&stack_a), (&stack_b)))) == get_way_b((&stack_a), (&stack_b)))
			move_b_pa(&stack_a, &stack_b);
		else
			move_ab_pa(&stack_a, &stack_b);
	}
	min_index = get_index(&stack_a, get_min(&stack_a));
	if (min_index > stack_a.size / 2)
		scroll_down(&stack_a, &stack_b, stack_a.size - min_index, 'a');
	else
		scroll_up(&stack_a, &stack_b, min_index, 'a');
}
