/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moturki <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:17:17 by moturki           #+#    #+#             */
/*   Updated: 2023/10/26 21:24:11 by moturki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	ft_traitement(t_list info, char c)
{
	if (c == '%')
		info.tl += write(1, &c, 1);
	else if (c == 'c')
	{
		c = va_arg(info.args, int);
		info.tl += write(1, &c, 1);
	}
	else if (c == 's')
		info = ft_traitement_string(info);
	else if (c == 'd' || c == 'i')
		info = ft_traitement_int(info, c);
	else if (c == 'u')
		info = ft_traitement_unsigned(info, c);
	else if (c == 'p')
		info = ft_traitement_ptr(info, c);
	else if (c == 'X' || c == 'x')
		info = ft_traitement_hexa(info, c);
	return (info);
}

int	ft_printf(const char *format, ...)
{
	t_list	info;
	size_t	i;

	i = 0;
	info.tl = 0;
	va_start(info.args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			info = ft_traitement(info, format[i + 1]);
			i += 2;
		}
		else
			info.tl += write(1, &format[i++], 1);
	}
	va_end(info.args);
	return (info.tl);
}
