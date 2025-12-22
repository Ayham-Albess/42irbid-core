/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:02:52 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 10:40:10 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && (i + j < len) && big[i + j] == little[j])
			j++;
		if (!little[j])
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char *c = "ayham albess";
	char *c2 = "albess";
	char *res = ft_strnstr(c,c2,11);
	if (res)
		printf("%s\n",res);
	else
		printf("NULL");
}
*/
