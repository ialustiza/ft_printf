#include <stdarg.h>
#include <unistd.h>

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

int main(void)
{
	ft_printf("%s %i%c%p", "Kaixo", 42, '\t', 2687);
}
