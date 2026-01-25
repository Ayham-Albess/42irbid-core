#include "push_swap.h"

void	sort_by_disorder(t_stack **a, t_stack **tail_a, t_stack **b, t_stack ** tail_b)
{
	float	disorder;

	disorder = disorder(a, tail_a);
	if (!*a)
		return ;
	if (disorder < 0.2)
		Simple(&a, &tail_a, &b, &tail_b);
	else if (disorder < 0.5)
		Medium(&a, &tail_a, &b, &tail_b);
	else if (disorder >= 0.5)
		Complex(&a, &tail_a, &b, &tail_b);
}
