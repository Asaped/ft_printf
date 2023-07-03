#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_ptr(unsigned long long n)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnbr_ptr(n / 16);
		ft_putnbr_ptr(n % 16);
	}
	else
		write(1, &tab[n], 1);
}

void	ft_putnbr_hexa(unsigned int n, size_t mode)
{
	char	*tab;

	if (mode == 1)
		tab = "0123456789abcdef";
	if (mode == 2)
		tab = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_putnbr_hexa(n / 16, mode);
		ft_putnbr_hexa(n % 16, mode);
	}
	else
		write(1, &tab[n], 1);
}

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
