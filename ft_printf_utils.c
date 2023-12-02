/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialustiz <ialustiz@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:54:14 by ialustiz          #+#    #+#             */
/*   Updated: 2023/11/21 15:13:04 by ialustiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
		len += ft_putchar(*s++);
	return (len);
}

int	ft_putnb(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		num *= -1;
		len = ft_putchar('-');
	}
	if (num > 9)
		len += ft_putnb(num / 10);
	len += ft_putchar((num % 10) + '0');
	return (len);
}

int	ft_putunsignb(unsigned int num)
{
	int	len;

	len = 0;
	if (num > 9)
		len += ft_putnb(num / 10);
	len += ft_putchar((num % 10) + '0');
	return (len);
}

int	ft_puthexa(size_t num, int upper)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthexa(num / 16, upper);
	if (upper)
		len += ft_putchar("0123456789ABCDEF"[num % 16]);
	else
		len += ft_putchar("0123456789abcdef"[num % 16]);
	return (len);
}
