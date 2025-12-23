/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:10:19 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 16:58:16 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_helper(unsigned long ptr)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_helper(ptr / 16);
	count += ft_putchar(hex[ptr % 16]);
	return (count);
}

int	ft_printf_point(unsigned long ptr)
{
	int		count;

	count = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	if (ptr != 0)
		count += ft_helper(ptr);
	return (count);
}
