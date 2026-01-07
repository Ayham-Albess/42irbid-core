/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:32:49 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/05 16:33:17 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->previous = tmp;
	*a = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->previous = tmp;
	*b = tmp;
}

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = *a;
	tmp->next = *a;
	tmp->previous = NULL;
	(*a)->previous = tmp;
	*a = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = *b;
	tmp->next = *b;
	tmp->previous = NULL;
	(*b)->previous = tmp;
	*b = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
