/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:09:12 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/08 15:37:01 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **s)
{
	int i = 0;
	if(!s)
		return;
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int set_strategy(t_algo* algo, char* flag)
{
    if (algo->set)
        return (0);
    if (ft_strcmp(flag, "--simple") == 0)
        algo->strategy = SIMPLE;
    else  if (ft_strcmp(flag, "--medium") == 0)
        algo->strategy = MEDIUM;
    else  if (ft_strcmp(flag, "--complex") == 0)
        algo->strategy = COMPLEX;
    else  if (ft_strcmp(flag, "--adaptive") == 0)
        algo->strategy = ADAPTIVE;
    else
        return (-1);
    algo->set = 1;
    return (1);
}

t_algo parse_flags(int* argc, char*** argv)
{
    t_algo algo;
    int i;
    int j;
    algo.strategy = ADAPTIVE;
    algo.bench = 0;
    algo.set = 0;
    i = 1;
    while (i < *argc)
    {
        if (set_strategy(&algo, (*argv)[i]) > 0);
        else if (ft_strcmp((*argv)[i], "--bench") == 0)
            algo.bench = 1;
        else
            break;
        j = i;
        while (j < *argc - 1)
        {
            (*argv)[j] = (*argv)[j + 1];
            j++;
        }
        (*argc)--;
    }
    return (algo);
}

void push_stack(t_stack* a, long num)
{
    t_node* new;

    new = malloc(sizeof(t_node));
    if (!new)
        return;
    new->value = num;
    new->index = -1;
    new->next = NULL;
    new->prev = NULL;

    if (a->size == 0)
    {
        a->head = new;
        a->tail = new;
    }
    else
    {
	    a -> tail->next = new;
	    new ->prev = a -> tail;
	    a->tail = new;
    }
    a->size++;
}

int get_numbers(int argc, char** argv, t_stack* a)
{
    int i;
    int j;
    char** tmp;

    i = 1;
    while (i < argc)
    {
        tmp = ft_split(argv[i], ' ');
        if (!tmp || !tmp[0])
            error();
        j = 0;
        while (tmp[j])
        {
            if (!number(tmp[j]) || has_dup(ft_atoi(tmp[j]), a))
            {
                free_split(tmp);
                error();
            }
            if (ft_atoi(tmp[j]) < INT_MIN || ft_atoi(tmp[j]) > INT_MAX)
                error();
            push_stack(a, ft_atoi(tmp[j]));
            j++;
        }
        free_split(tmp);
        i++;
    }
    return (1);
}
