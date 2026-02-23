/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:42:18 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/09 13:50:55 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *s)
{
	t_node	*temp;
	int		min;

	temp = s->head;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	get_pos(t_stack *s, int val)
{
	t_node	*temp;
	int		pos;

	temp = s->head;
	pos = 0;
	while (temp)
	{
		if (temp->value == val)
			break ;
		pos++;
		temp = temp->next;
	}
	return (pos);
}
