/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:46:20 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/21 15:14:25 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	Simple(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	int rotations;
	int len;
	int i;

	len = 0;
	rotations = 0;
	pb(a, b);
	pb(a ,b);
	len += 2;
	if ((*b) ->value < (*b)->previous->value)
		sb(b, 1);
	while (!(*a))
	{
		i = 0;
		while ( *b && ((*b) ->value > (*a) ->value) && i < len) 
		{
			rb(b, tailb, 1);
			rotations++;
			i++;
		}
		pb(a, b);
		len++;
		while (rotations--> 0)
			rrb(b, tailb, 1);
	}
}
