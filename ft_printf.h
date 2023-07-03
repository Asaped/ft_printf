#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> 

typedef struct s_list
{
	va_list	args;
	size_t	tl;
}				t_list;

int		ft_printf(const char *format, ...);

t_list	ft_printchar(t_list lst);

t_list	ft_traitement(char const format, t_list lst);

t_list	ft_printstring(t_list lst);

t_list	ft_printnum(t_list lst);

void	ft_putnbr(long long n);

void	ft_putchar(char c);

t_list	ft_printunsigned(t_list lst);

t_list	ft_printhexa(t_list lst, size_t mode);

void	ft_putnbr_hexa(unsigned int n, size_t mode);

void	ft_putnbr_ptr(unsigned long long n);

t_list	ft_printptr(t_list lst);

#endif
