/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:48:07 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 10:42:14 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*
char	to_upper(unsigned int i, char c)
{
	if (c >= 97 && c<= 122)
		return (c - 32);
	return (c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	p = (char *)malloc(i * 1 + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int main()
{
	char *c = "ayham";
	char *p = ft_strmapi(c,to_upper);
	printf("%s",p);
}
*/
