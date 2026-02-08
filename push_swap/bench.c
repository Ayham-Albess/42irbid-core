/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:08:57 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 15:48:19 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_disorder(float disorder)
{
	int	x;
	int	y;

	x = disorder * 100;
	y = disorder * 1000;
	y = y - (x * 100);
	ft_printf_d(x);
	write(2, ".", 1);
	ft_printf_d(y);
	if (y == 0)
	{
		write(2, "0", 1);
	}
	write(2, "%", 1);
}

static void	print_strategy(t_algo *algo, float disorder)
{
	if (algo -> strategy == SIMPLE)
		write(2, "Simple / O(n*n)", 15);
	else if (algo -> strategy == MEDIUM)
		write(2, "Medium / O(n√n)", 15);
	else if (algo -> strategy == COMPLEX)
		write(2, "Complex / O(nlogn)", 18);
	else
	{
		if (disorder < 0.2)
			write(2, "Adaptive / O(n*n)", 17);
		else if (disorder < 0.5)
			write(2, "Adaptive / O(n√n)", 17);
		else
			write(2, "Adaptive / O(nlogn)", 19);
	}
	write(2, "\n", 1);
}

static void	print_ops(t_stack *a)
{
	write (2, "[bench]", 7);
	write (2, " sa:  ", 6);
	ft_printf_d(a->bench->counts[OP_SA]);
	write (2, "  sb:  ", 7);
	ft_printf_d(a->bench->counts[OP_SB]);
	write (2, "  ss:  ", 7);
	ft_printf_d(a->bench->counts[OP_SS]);
	write (2, "  pa:  ", 7);
	ft_printf_d(a->bench->counts[OP_PA]);
	write (2, "  pb:  ", 7);
	ft_printf_d(a->bench->counts[OP_PB]);
	write (2, "\n[bench] ra:  ", 14);
	ft_printf_d(a->bench->counts[OP_RA]);
	write (2, "  rb:  ", 7);
	ft_printf_d(a->bench->counts[OP_RB]);
	write (2, "  rr:  ", 7);
	ft_printf_d(a->bench->counts[OP_RR]);
	write (2, "  rra:  ", 8);
	ft_printf_d(a->bench->counts[OP_RRA]);
	write (2, "  rrb:  ", 8);
	ft_printf_d(a->bench->counts[OP_RRB]);
	write (2, "  rrr:  ", 8);
	ft_printf_d(a->bench->counts[OP_RRR]);
	write(2, "\n", 1);
}

void	print_bench(t_stack *a, t_algo *algo, float disorder)
{
	write(2, "[bench] disorder:  ", 19);
	print_disorder(disorder);
	write(2, "\n[bench] strategy:  ", 20);
	print_strategy(algo, disorder);
	write(2, "[bench] total_ops:  ", 20);
	ft_printf_d(a->bench->counts[TOTAL_OP]);
	write(2, "\n", 1);
	print_ops(a);
}
