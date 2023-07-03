#include "ft_printf.h"

t_list	ft_printptr(t_list lst)
{
	unsigned long long	n;

	n = va_arg(lst.args, unsigned long long);
	if (n == 0)
	{
		lst.tl += write(1, "(nil)", 5);
		return (lst);
	}
	lst.tl += write(1, "0x", 2);
	ft_putnbr_ptr(n);
	while (n >= 16)
	{
		n /= 16;
		lst.tl++;
	}
	lst.tl++;
	return (lst);
}

t_list	ft_printhexa(t_list lst, size_t mode)
{
	unsigned int	n;

	n = va_arg(lst.args, unsigned int);
	ft_putnbr_hexa(n, mode);
	while (n >= 16)
	{
		n /= 16;
		lst.tl++;
	}
	lst.tl++;
	return (lst);
}
