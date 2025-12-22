/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:26:33 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/15 16:34:07 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	total;
	size_t	i;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	p = (char *)malloc(total);
	if (!p)
		return (NULL);
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
/*
int main()
{
	char *c = ft_calloc(5,1);
	c[0] = 'a';
	printf("%s\n",c);
}
*/
