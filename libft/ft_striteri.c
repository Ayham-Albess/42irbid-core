/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:09:16 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/11 10:41:22 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*
void    to_upper(unsigned int i, char *c)
{
        if (*c >= 97 && *c <= 122)
                *c = *c - 32;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main()
{
        char c[] = "ayham";
        ft_striteri(c,to_upper);
        printf("%s",c);
}
*/
