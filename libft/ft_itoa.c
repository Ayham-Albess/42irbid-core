/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:55:27 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/15 17:18:38 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_fillstr(char *str, long num, int len, int sign)
{
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;
	int		sign;

	num = n;
	sign = 0;
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_fillstr(str, num, len, sign);
	return (str);
}
