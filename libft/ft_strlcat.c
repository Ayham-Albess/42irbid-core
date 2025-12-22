/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:41:44 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 10:40:45 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	len2 = 0;
	i = 0;
	while (dst[len1] && len1 < size)
		len1++;
	while (src[len2])
		len2++;
	if (size <= len1)
		return (size + len2);
	while (src[i] && (len1 + i) < (size - 1))
	{
		dst[len1 + i] = src[i];
		i++;
	}
	if (len1 + i < size)
		dst[len1 + i] = '\0';
	return (len1 + len2);
}
/*
int main()
{
    char d[12] = "ayham";
    char s[7]  = "albess";

    size_t res = ft_strlcat(d, s, 12);

    printf("%d\n", res);
    printf("%s\n", d);
    printf("%s\n", s);
}
*/
