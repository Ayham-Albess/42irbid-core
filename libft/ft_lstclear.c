/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:20:24 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 12:28:26 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p1;
	t_list	*p2;

	if (!lst || !del)
		return ;
	p2 = *lst;
	while (p2)
	{
		p1 = p2->next;
		del(p2->content);
		free(p2);
		p2 = p1;
	}
	*lst = NULL;
}
