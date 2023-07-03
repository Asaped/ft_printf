#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	lst;
	size_t	i;

	i = 0;
	lst.tl = 0;
	va_start(lst.args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			lst = ft_traitement(format[i], lst);
		}
		else
			lst.tl += write(1, &format[i], 1);
		i++;
	}
	va_end(lst.args);
	return (lst.tl);
}
