#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **taila, t_stack **b, t_stack **tailb)
{
	int	low;
	int	high;
	int	window;

	window = window_size(stack_len(a));
	low = 0;
	high = window;
	while (*a)
	{
		if((*a) -> value >= low && (*a) -> value <= high)
		{
			pb(a, b);
			if((*a) -> value < low + window / 2)
				rb(b, tailb, 1);
			low++;
			high++;
		}
		else if ((*a) -> value < low)
		{
			pb(a,b);
			rb(b, tailb, 1);
			low++;
			high++;
		}
		else
			ra(a,taila, 1);
	}
}
void	push_back(t_stack **a, t_stack **b)
{
	if (!((*b) -> previous))
		return;
	while (*b)
	{
		if ((*b)->value < (*b) ->previous->value)
			sb(b, 1);
		while ((*b) -> value > (*a) -> value)
		{
			ra(a, taila, 1);
			rotations++;
		}
		pa(a, b);
		while (rotaions-- > 0)
			rra(a, taila, 1);
	}
}
void	set_values(t_stack **a, int *p)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		tmp ->value = p[tmp ->value];
		tmp = tmp -> previous;
	}
}

void	Medium(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	int	i;
	int	*p;
	int	len;
	int	window;
	t_stack	*tmp;

	i = 0;
	len = stack_len(a);
	window = window_size(len);
	tmp = *a;
	p = malloc (len * sizeof(int));
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->next;
	}
	sort_p(p);
	set_index(a,p);
	push_to_b(a, taila, b, tailb);
	push_back(a, b);
	set_values(a, p);
}
