/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moturki <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:16:54 by moturki           #+#    #+#             */
/*   Updated: 2023/11/07 19:19:46 by moturki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	ft_traitement_hexa(t_list info, char c)
{
	unsigned int	nb;

	nb = va_arg(info.args, unsigned int);
	info.tl += ft_putnbr_base(nb, 16, c, 0);
	return (info);
}

t_list	ft_traitement_ptr(t_list info, char c)
{
	size_t	nb;

	nb = va_arg(info.args, size_t);
	info.tl += write(1, "0x", 2) + ft_putnbr_base(nb, 16, c, 0);
	return (info);
}

t_list	ft_traitement_unsigned(t_list info, char c)
{
	unsigned int	nb;

	nb = va_arg(info.args, unsigned int);
	info.tl += ft_putnbr_base(nb, 10, c, 0);
	return (info);
}

t_list	ft_traitement_int(t_list info, char c)
{
	int				nb;

	nb = va_arg(info.args, int);
	info.tl += ft_putnbr_base(nb, 10, c, 0);
	return (info);
}

t_list	ft_traitement_string(t_list info)
{
	char	*str;
	size_t	i;

	i = 0;
	str = va_arg(info.args, char *);
	if (!str)
	{
		info.tl += write(1, "(null)", 6);
		return (info);
	}
	while (str[i])
		info.tl += write(1, &str[i++], 1);
	return (info);
}
