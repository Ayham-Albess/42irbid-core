/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:34:53 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/05 16:35:18 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b, t_stack **ta, t_stack **tb)
{
	rra(a, ta);
	rrb(b, tb);
}

void	check_order(t_stack *a, t_stack *tail)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_len(a) - 1)
	{
		j = i++ + 1;
		while (j++ < stack_len(a) - 1)
		{
			total_pairs++;
			if (a ->value > a ->next->value)
				mistakes++;
		}
	}
	if ((mistakes / total_pairs) < 0.2)
		simple();
	if (0.2 <= (mistakes / total_pairs) < 0.5)
		medium();
	if ((mistakes / total_pairs) >= 0.5)
		complix();
}
