/* * - = NULL;
 * tailb = NULL;
 ******************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:00:43 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/05 14:31:12 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

stack *ft_lstnew(int value)
{
    stack *node = malloc(sizeof(stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

int	valid (char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while(s[i][j])
		{
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	dup(char **s)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		j = i + 1;
		while (s[j])
		{
			if (num == ft_atoi(s[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (valid(s));
}

stack *init_a(char **s, stack *tail)
{
	int 	i;
	stack	*head;
	stack	*temp;

	if (dup(s))
	{
		write(2, "Error\n", 5)
		return (NULL);
	}
	i = 0;
	if (!s[i])
		return (NULL);
	head = ft_lstnew(ft_atoi(s[i]));
	if (!head)
		return (NULL);
	i++;
	tail = head;
	while (s[i])
	{
		tail -> next = ft_lstnew(ft_atoi(s[i++]));
		temp = tail;
		tail = tail ->next;
		tail -> previous = temp;
	}
	return (head);
}	
int main(int argc, char **argv)
{
	char **words;
	stack *a;
	stack *b;
	stack *taila;
	stack *tailb

	a = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		words = ft_split(argv[1], ' ');
		a = init_a(words, taila); 
	}
	else
		a = init_a(argv, taila);
	b = NULL;
	tailb = NULL;
	check_order(a, taila);
	printf("%s", words[3]);
	return (0);
}
