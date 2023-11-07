/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moturki <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:42:00 by moturki           #+#    #+#             */
/*   Updated: 2023/11/07 19:20:23 by moturki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long int nb, unsigned int base, char c, int count)
{
	size_t	nbr;
	char	*str;

	if (base == 10)
		str = "0123456789";
	else if (c == 'x' || c == 'p')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nb < 0 && c != 'p')
	{
		nbr = (size_t)(-nb);
		count += write(1, "-", 1);
	}
	else
		nbr = (size_t)nb;
	if (nbr >= base)
	{
		count += ft_putnbr_base(nbr / base, base, c, 0);
		count += ft_putnbr_base(nbr % base, base, c, 0);
	}
	else
		count += write(1, &str[nbr], 1);
	return (count);
}
