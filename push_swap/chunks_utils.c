/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:55:02 by raaalali          #+#    #+#             */
/*   Updated: 2026/02/09 13:50:24 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_node*top, int target_index)
{
	int	pos;

	pos = 0;
	while (top)
	{
		if (top->index == target_index)
			return (pos);
		top = top->next;
		pos++;
	}
	return (-1);
}

int	calculate_chunk(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

int	get_max_index(t_stack*s)
{
	t_node	*current;
	int		max;

	if (!s || !s->head)
		return (-1);
	current = s->head;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static void	sort_array(int *tmp, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp[i] > tmp[j])
			{
				t = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = t;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_sorted_array(t_stack *a)
{
	int		*tmp;
	int		i;
	t_node	*current;

	tmp = malloc(sizeof(int) * a->size);
	if (!tmp)
		return (NULL);
	current = a->head;
	i = 0;
	while (current)
	{
		tmp[i++] = current->value;
		current = current->next;
	}
	sort_array(tmp, a->size);
	return (tmp);
}
