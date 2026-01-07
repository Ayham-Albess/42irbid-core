#include "push_swap.h"

int	stack_len(t_stack *t)
{
	int	i;

	i = 0;
	while (t)
	{
		i++;
		t = t->next;
	}
	return (i);
}

t_stack	*find_last_node(t_stack *t)
{
	if (!t)
		return (NULL);
	while (t->next)
		t = t->next;
	return (t);
}

bool	sorted(t_stack *t)
{
	if (!t)
		return (true);
	while (t->next)
	{
		if (t->value > t->next->value)
			return (false);
		t = t->next;
	}
	return (true);
}
