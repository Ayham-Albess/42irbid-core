/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:00:17 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 16:21:43 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handel(char c, va_list args)
{
	if (c == 'c' || c == 's')
		return (ft_printf_str(c, args));
	if (c == 'i' || c == 'd' || c == 'u')
		return (ft_printf_int(c, args));
	if (c == 'p')
		return (ft_printf_point((unsigned long)va_arg(args, void *)));
	if (c == 'x')
		return (ft_printf_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;

	if (!str)
		return (ft_putstr("(null)"));
	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			i += handel(*(++str), args);
		}
		else
		{
			i++;
			write(1, &*str, 1);
		}
		str++;
	}
	va_end(args);
	return (i);
}
