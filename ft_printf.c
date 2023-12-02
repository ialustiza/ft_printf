/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialustiz <ialustiz@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:43:47 by ialustiz          #+#    #+#             */
/*   Updated: 2023/11/21 16:49:48 by ialustiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conditions(va_list va, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(va, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_puthexa(va_arg(va, size_t), 0));
	else if (c == 'd' || c == 'i')
		return (ft_putnb(va_arg(va, int)));
	else if (c == 'u')
		return (ft_putunsignb(va_arg(va, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(va, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthexa(va_arg(va, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int	len;
	va_list	va;

	len = 0;
	va_start(va, s);
	while (*s)
	{
		if (*s == '%')
			len += ft_conditions(va, *(++s));
		else
			len += ft_putchar(*s);
		s++;
	}
	va_end(va);
	return (len);
}
