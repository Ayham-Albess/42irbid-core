/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:12:36 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 15:44:13 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unsignedint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_unsignedint(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_integer_decimal(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_integer_decimal(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_printf_int(char c, va_list args)
{
	if (c == 'u')
		return (ft_unsignedint(va_arg(args, unsigned int)));
	else
		return (ft_integer_decimal(va_arg(args, int)));
}
