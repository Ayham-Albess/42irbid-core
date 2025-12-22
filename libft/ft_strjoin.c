/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:08:42 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/15 15:33:24 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

static void	join(char const *s1, char const *s2, char *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
		{
			p[i] = s2[j];
			i++;
			j++;
		}
	}
	p[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != NULL)
		while (s1[i])
			i++;
	if (s2 != NULL)
		while (s2[j])
			j++;
	if (!s1 && !s2)
		return (NULL);
	p = (char *)malloc((i + j) * 1 + 1);
	if (p == NULL)
		return (NULL);
	join(s1, s2, p);
	return (p);
}
/*
int main()
{
	char *c = "ayham";
	char *c2 = "albess";
	char *p = ft_strjoin(c,c2);
	printf("%s",p);
}
*/
