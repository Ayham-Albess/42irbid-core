/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:42:04 by aalbess           #+#    #+#             */
/*   Updated: 2025/12/22 16:21:52 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *str, ...);
int	ft_printf_point(unsigned long ptr);
int	ft_printf_str(char c, va_list args);
int	ft_printf_hex(unsigned int nbr, int u);
int	ft_printf_int(char c, va_list args);
#endif
