/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:27:56 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 12:06:24 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int c)
{
	t_node *first;
	t_node *second;

	if(!a || a->size < 2)
		return ;
	first = a->head;
	second = first->next;
	first ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second;
	a->head = second;
	if(a->size == 2)
		a->tail = first;
	if(c == 0)
	{
		a->bench->counts[OP_SA]++;
		a->bench->counts[TOTAL_OP]++;
		write(1, "sa\n", 3);
	}
}
void	sb(t_stack *a, t_stack *b, int c)
{
	t_node *first;
	t_node *second;

	if(!b || b ->size <2)
		return ;
	first = b ->head;
	second = first ->next;
	first ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second ;
	b->head = second ;
	if(b->size == 2)
		b->tail = first;
	if (c == 0)
	{
		a->bench->counts[OP_SB]++;
		a->bench->counts[TOTAL_OP]++;
		write(1, "sb\n", 3);
	}
}
void ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(a, b, 1);
	a->bench->counts[OP_SS]++;
	a->bench->counts[TOTAL_OP]++;
	write (1,"ss\n", 3);
}
void pa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if(b->size == 0)
		return ;

	tmp = b->head ->next;
	b->head ->next = a->head ;
	if(a->head)
		a ->head ->prev = b->head;
	b->head ->prev = NULL;
	a->head = b->head;
	if (a->size == 0)
		a->tail = a->head;
	if (b ->size == 1)
		b->tail = NULL;
	b -> head = tmp;
	if(b -> head)
		b->head->prev = NULL;
	a->size++;
	b->size--;
	a->bench->counts[OP_PA]++;
	a->bench->counts[TOTAL_OP]++;
	write (1, "pa\n", 3);
}
	
void pb(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if(a->size == 0)
		return ;
	tmp = a->head ->next;
	a->head ->next = b->head;
	if(b -> head)
		b->head ->prev = a->head;
	a->head ->prev= NULL;
	b->head = a->head;
	if(b->size == 0)
		b->tail = a->head;
	if(a->size == 1)
		a->tail = NULL;
	a -> head = tmp;
	if(a -> head)
		a->head->prev = NULL;
	a->size--;
	b->size++;
	a->bench->counts[OP_PB]++;
	a->bench->counts[TOTAL_OP]++;
	write(1,"pb\n", 3);
}
