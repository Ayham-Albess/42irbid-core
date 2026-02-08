/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:43:32 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 14:58:03 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a, int c)
{
	t_node *tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->head ->next;
	a->tail->next = a->head;
	a->head ->prev = a->tail;
	a->head ->next = NULL;
	a->tail = a->head;
	a->head = tmp;
	a->head-> prev = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RA]++;
		a->bench->counts[TOTAL_OP]++;
		write(1, "ra\n", 3);
	}
}
void rb(t_stack *a, t_stack *b, int c)
{
    t_node *old_head;

    if (!b || b->size < 2)
        return;

    old_head = b->head;

    // Move head forward
    b->head = old_head->next;
    b->head->prev = NULL;

    // Put old head at the end
    b->tail->next = old_head;
    old_head->prev = b->tail;

    old_head->next = NULL;
    b->tail = old_head;

    if (c == 0)
    {
        a->bench->counts[OP_RB]++;
        a->bench->counts[TOTAL_OP]++;
        write(1, "rb\n", 3);
    }
}

/*
void rb(t_stack *a, t_stack *b, int c)
{
	t_node *tmp;

	if(!b || b->size < 2)
		return ;
	tmp = b->head ->next;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->head->next = NULL;
	b->tail = b->head;
	b->head = tmp;
	b->head->prev = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RB]++;
		a->bench->counts[TOTAL_OP]++;
		write(1, "rb\n", 3);
	}
}*/
void rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	rb(a, b, 1);
	a->bench->counts[OP_RR]++;
	a->bench->counts[TOTAL_OP]++;
	write(1, "rr\n", 3);
}
void rra (t_stack *a, int c)

{
	t_node *tmp;

	if(!a || a->size < 2)
		return ;
	tmp = a->tail->prev;
	a->tail->next = a->head;
	a->head ->prev = a->tail;
	a->tail->prev = NULL;
	a->head = a->tail;
	a->tail = tmp;
	tmp ->next = NULL;
	if (c == 0)
	{
		a->bench->counts[OP_RRA]++;
		a->bench->counts[TOTAL_OP]++;
		write(1,"rra\n", 4);
	}
}
void rrb(t_stack *a,t_stack *b, int c)
{
	t_node *tmp;

	if(!b || b->size < 2)
		return ;
	tmp = b->tail->prev;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->tail->prev= NULL;
	b->head = b->tail;
	b->tail = tmp;
	tmp ->next = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RRB]++;
		a->bench->counts[TOTAL_OP]++;
		write(1,"rrb\n", 4);
	}
}
