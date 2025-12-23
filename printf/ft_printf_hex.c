/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:57:52 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 16:17:20 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_hex(unsigned int nbr, int u)
{
	char	*hex;
	int		count;

	count = 0;
	if (u == 0)
		hex = "0123456789abcdef";
	else if (u == 1)
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_printf_hex(nbr / 16, u);
	count += ft_putchar(hex[nbr % 16]);
	return (count);
}
