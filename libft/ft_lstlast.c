/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:46:32 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 11:56:28 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
/*
int main(void)
{
    t_list *head = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;
    int a = 1;
    int b = 2;
    int c = 3;
    node1 = malloc(sizeof(t_list));
    node1->content = &a;
    node1->next = NULL;
    node2 = malloc(sizeof(t_list));
    node2->content = &b;
    node2->next = NULL;
    node3 = malloc(sizeof(t_list));
    node3->content = &c;
    node3->next = NULL;
    head = node1;
    node1->next = node2;
    node2->next = node3;
    t_list *last = ft_lstlast(head);
    if (last)
        printf("%d\n", *(int *)last->content);
}
*/
