#include "ft_printf.h"

t_list	ft_printunsigned(t_list lst)
{
	unsigned int	n;

	n = va_arg(lst.args, unsigned int);
	ft_putnbr(n);
	while (n >= 10)
	{
		n /= 10;
		lst.tl++;
	}
	lst.tl++;
	return (lst);
}

t_list	ft_printnum(t_list lst)
{
	int		n;

	n = va_arg(lst.args, long long);
	ft_putnbr(n);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			lst.tl += 11;
			return (lst);
		}
		lst.tl++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		lst.tl++;
	}
	lst.tl++;
	return (lst);
}

t_list	ft_printstring(t_list lst)
{
	char	*str;
	size_t	i;

	i = 0;
	str = va_arg(lst.args, char *);
	if (!str)
	{
		lst.tl += write(1, "(null)", 6);
		return (lst);
	}
	while (str[i])
		lst.tl += write(1, &str[i++], 1);
	return (lst);
}

t_list	ft_printchar(t_list lst)
{
	int		c;

	c = va_arg(lst.args, int);
	lst.tl += write(1, &c, 1);
	return (lst);
}

t_list	ft_traitement(char const format, t_list lst)
{
	if (format == 'c')
		lst = ft_printchar(lst);
	else if (format == 's')
		lst = ft_printstring(lst);
	else if (format == 'i' || format == 'd')
		lst = ft_printnum(lst);
	else if (format == 'u')
		lst = ft_printunsigned(lst);
	else if (format == 'x')
		lst = ft_printhexa(lst, 1);
	else if (format == 'X')
		lst = ft_printhexa(lst, 2);
	else if (format == 'p')
		lst = ft_printptr(lst);
	else if (format == '%')
		lst.tl += write(1, "%", 1);
	return (lst);
}
