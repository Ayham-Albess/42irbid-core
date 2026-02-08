/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:08:30 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 14:09:09 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_stack(t_stack *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	s->bench = malloc(sizeof(t_bench));
	if (s->bench)
		ft_memset(s->bench->counts, 0, sizeof(s->bench->counts));
}

void sort_p(int *p, int n)
{
	int i;
	int tmp;
	int swapped;
	
	while (n > 1)
	{
		swapped = 0;
		i = 0;
		while (i < n -1)
		{
			if(p[i] > p[i + 1])
			{
				tmp = p[i];
				p[i] = p[i + 1]; 
				p[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		if(!swapped)
			break;
		n--;
	}
}

void set_index(t_node *node, int *p, int size)
{
	int i;
	while (node)
	{
		i = 0;
		while (i<size)
		{
			if(p[i] == node->value)
			{
				node->index = i;
				break;
			}
			i++;
		}
		node = node -> next;
	}
}

void indexing (t_stack *a)
{
	int *p;
	int i;
	t_node *tmp;

	i = 0;
	p = malloc (a->size *sizeof(int));
	tmp = a->head;
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->next;
	}
	sort_p(p, a->size);
	tmp = a->head;
	set_index(a->head, p, a->size);
	free(p);
}

int main(int argc, char** argv)
{
    t_stack a;
    t_stack b;
    t_algo algo;

    init_stack(&a);
    init_stack(&b);
    
    if (argc < 2)
        return (0);
    algo = parse_flags(&argc, &argv);
    if (!get_numbers(argc, argv, &a))
	    error();
    indexing(&a);
    if(sorted(&a))
	    return (0);
    sort(&a, &b, &algo);

    return (0);

}
