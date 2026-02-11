/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:52:47 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 14:12:13 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	window_size(int size)
{
	if (size <= 100)
		return (15);
	else
		return (35);
}

static void	push_to_b(t_stack *a, t_stack *b, int window)
{
	int		low;
	int		high;
	t_node	*tmp;

	low = 0;
	high = window;
	tmp = a ->head;
	while (tmp)
	{
		if (tmp ->index >= low && tmp ->index <= high)
		{
			pb(a, b);
			if (tmp ->index < (low++) + window / 2)
				rb(a, b, 0);
			high++;
		}
		else if (tmp ->index < low++)
		{
			pb(a, b);
			rb(a, b, 0);
			high++;
		}
		else
			ra(a, 0);
	}
}

static void	push_back(t_stack *a, t_stack *b)
{
	simple(b, a);
	/*
	int 	rotate;

	pa(a, b);
	pa(a, b);
	if (a ->head ->value > a ->head ->next ->value)
		sa(a, 0);
	while (b -> head)
	{
		rotate = 0;
		while (b ->head ->value > a ->head->value)
		{
			rotate++;
			ra(a, 0);
		}
		pa(a, b);
		while (rotate-- > 0)
			rra(a, 0);
	}
	*/
}

void	medium(t_stack *a, t_stack *b)
{
	int	window;

	window = window_size(a ->size);
	push_to_b(a, b, window);
	push_back(a, b);
}
