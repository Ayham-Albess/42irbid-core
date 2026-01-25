#include "push_swap.h"

void	sa(t_stack** a, int c)
{
	t_stack* tmp;
	if (!a || !*a || !(*a)->next)
		return;
	tmp = (*a) ->next;
	(*a)->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = *a;
	tmp->next = (*a);
	tmp->previous = NULL;
	(*a)->previous = tmp;
	*a = tmp;
	if (c == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack** b, int c)
{
	t_stack* tmp;

	if (!b || !*b || !(*b)->next)
		return;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = *b;
	tmp->next = (*b);
	tmp->previous = NULL;
	(*b)->previous = tmp;
	*b = tmp;
	if (c == 1)
		write(1, "sb\n", 3);

}

void	ss(t_stack** a, t_stack** b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack** a, t_stack **b)
{
	t_stack* tmp;

	tmp = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	tmp->next = *a;
	(*a)->previous = tmp;
	tmp->previous - NULL;
	*a = tmp;
	write(1, "pa\n", 3);

}

void	pb(t_stack **a, t_stack** b)
{
	t_stack* tmp;

	tmp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	tmp->next = *b;
	(*b)->previous = tmp;
	tmp->previous - NULL;
	*b = tmp;
	write(1, "pb\n", 3);
}
