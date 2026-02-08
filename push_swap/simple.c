/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:25:48 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 15:53:13 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_min(t_stack *s)
{
	t_node *temp;
	int		min;

	temp = s -> head;
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

	temp = s -> head;
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

void	simple(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;
	int	size;

	size = a -> size;
	while (size > 1)
	{
		min = get_min(a);
		pos = get_pos(a, min);
		if (pos == 1)
			sa(a, 0);
		else if (pos <= size / 2)
			while (a->head->value != min)
				ra(a, 0);
		else
			while (a ->head->value != min)
				rra(a, 0);
		if (size > 2)
			pb(a, b);
		size--;
	}
	while (b -> head)
		pa(a, b);
}
