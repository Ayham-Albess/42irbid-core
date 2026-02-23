/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:51:32 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/09 16:03:12 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp)
	{
		a->head = a ->head ->next;
		free(tmp);
		tmp = a-> head;
	}
	free(a ->bench);
}

int	lm(long num)
{
	if (num < INT_MIN && num > INT_MAX)
		return (error(), 0);
	else
		return (1);
}

void	valid(t_stack *a, char **tmp, int j)
{
	if (!num(tmp[j]) || dupp(ft_atoi(tmp[j]), a))
	{
		free_split(tmp);
		error();
	}
	if (ft_atoi(tmp[j]) < INT_MIN || ft_atoi(tmp[j]) > INT_MAX)
		error();
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rrb(a, b, 1);
	a->bench->counts[OP_RRR]++;
	a->bench->counts[TOTAL_OP]++;
	write(1, "rrr\n", 4);
}
