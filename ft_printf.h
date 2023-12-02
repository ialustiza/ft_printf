/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialustiz <ialustiz@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:43:54 by ialustiz          #+#    #+#             */
/*   Updated: 2023/11/21 15:10:36 by ialustiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnb(int num);
int	ft_putunsignb(unsigned int num);
int	ft_puthexa(size_t arg, int upper);
int	ft_conditions(va_list va, char c);
int	ft_printf(const char *s, ...);

#endif
