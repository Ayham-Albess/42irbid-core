/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:38:59 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 13:50:09 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int		max;
	int		num_of_bits;
	t_node	*tmp;

	if (!a)
		return (0);
	tmp = a -> head;
	num_of_bits = 0;
	max = tmp ->index;
	while (tmp)
	{
		if (tmp ->index > max)
			max = tmp ->index;
		tmp = tmp ->next;
	}
	while (1 << num_of_bits <= max)
		num_of_bits++;
	return (num_of_bits);
}

void	complexx(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	bits;

	bits = max_bits(a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < a -> size)
		{
			if ((a -> head-> index >> i & 1) == 0)
				pb(a, b);
			else
				ra(a, 0);
			j++;
		}
		while (b -> size > 0)
			pa(a, b);
		i++;
	}
}
