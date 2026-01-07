/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:33:59 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/05 16:34:31 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack **a, t_stack **tail)
{
	t_stack	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	(*tail)->next = tmp;
	tmp->previous = *tail;
	tmp->next = NULL;
	*tail = tmp;
}

void	rb(t_stack **b, t_stack **tail)
{
	t_stack	*tmp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	(*tail)->next = tmp;
	tmp->previous = *tail;
	tmp->next = NULL;
	*tail = tmp;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a, t_stack **tail)
{
	t_stack	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*tail)->previous;
	(*tail)->next = *a;
	(*tail)->previous = NULL;
	(*a)->previous = *tail;
	tmp->next = NULL;
	*a = *tail;
	*tail = tmp;
}

void	rrb(t_stack **b, t_stack **tail)
{
	t_stack	*tmp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp = (*tail)->previous;
	(*tail)->next = *b;
	(*tail)->previous = NULL;
	(*b)->previous = *tail;
	tmp->next = NULL;
	*b = *tail;
	*tail = tmp;
}
