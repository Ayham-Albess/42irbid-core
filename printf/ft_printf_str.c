/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:48:41 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 16:59:26 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_str(char c, va_list args)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (ft_putstr("(null)"));
		return (ft_putstr(str));
	}
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	return (0);
}
