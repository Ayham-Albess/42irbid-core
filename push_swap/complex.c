/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:47:22 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/21 18:31:54 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	Complex(t_stack **a,  t_stack **taila, t_stack **b, t_stack **tailb)
{
	int	*p;
	int	bit;
	int	len;

	bit = 0;
	len = stack_len(a);
	p = malloc (len * sizeof(int));
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->next;
	}
	sort_p(p);
	set_index(a, p);
	while (bit < 9)
	{
		while (*a)
		{
			if (((*a) -> value >>bit & 1) == 0)
				pb(a,b);
			else
				ra(a, taila);
		}
		while (*b)
			pa(a,b);
		bit++;
	}

