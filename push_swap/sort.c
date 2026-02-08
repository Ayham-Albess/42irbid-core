/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:18:00 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 14:14:02 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b, t_algo *algo)
{
	float disorder;

	disorder = compute_disorder(a);

	if (algo->strategy == SIMPLE)
		simple(a, b);
	else if(algo->strategy == MEDIUM)
		medium(a, b);
	else if(algo -> strategy== COMPLEX)
		complexx(a, b);
	else 
	{
		if (disorder < 0.2)
			simple(a, b);
		else if (disorder < 0.5)
			medium(a, b);
		else 
			complexx(a, b);
	}
	if (algo->bench == 1)
		print_bench(a, algo, disorder);
}
