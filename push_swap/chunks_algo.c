/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:54:40 by raaalali          #+#    #+#             */
/*   Updated: 2026/02/09 13:55:21 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium(t_stack*a, t_stack*b)
{
	int	chunk_size;

	chunk_size = calculate_chunk(a->size);
	push_to_b(a, b, chunk_size);
	back_to_a(a, b);
}

void	push_to_b(t_stack*a, t_stack*b, int chunk_size)
{
	int	i;

	i = 0;
	while (a->head)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->head->index <= (i + chunk_size))
		{
			pb(a, b);
			rb(a, b, 0);
			i++;
		}
		else
			ra(a, 0);
	}
}

void	back_to_a(t_stack*a, t_stack*b)
{
	int	max_idx;

	while (b->head)
	{
		max_idx = get_max_index(b);
		if (get_position(b->head, max_idx) <= b->size / 2)
		{
			while (b->head->index != max_idx)
				rb(a, b, 0);
		}
		else
		{
			while (b->head->index != max_idx)
				rrb(a, b, 0);
		}
		pa(a, b);
	}
}
