#include "push_swap.h"

void sort_p(int *p)
{
}
int find_index(int *p, int value)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if(p[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
void set_index(t_stack **a, int *p)
{
	t_stack *tmp;

	tmp = *a
	while (tmp)
	{
		tmp -> value = find_index(p, tmp ->value);
		tmp = tmp ->next;
	}
}
int	window_size(int len)
{
	if(len <= 100)
		return (20);
	else
		return (45);
}
