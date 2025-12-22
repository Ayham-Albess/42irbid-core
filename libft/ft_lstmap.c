/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:17:06 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/15 15:24:17 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include "libft.h"

int	node(t_list **new_list, t_list *lst,
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*content;

	content = f(lst->content);
	if (!content)
		return (0);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		return (0);
	}
	ft_lstadd_back(new_list, new_node);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (!node(&new_list, lst, f, del))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_list);
}
/*
void	del(void *content)
{
	free(content);
}

void	*to_upper(void *content)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)content;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		else
			new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	main(void)
{
	t_list	*lst;
	t_list	*mapped;
	t_list	*tmp;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("libft")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	mapped = ft_lstmap(lst, to_upper, del);
	tmp = mapped;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);
	return (0);
}
*/
