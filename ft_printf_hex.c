/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrahoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:33:34 by adrahoto          #+#    #+#             */
/*   Updated: 2025/12/16 18:33:54 by adrahoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_puthex(unsigned int nb)
{
	char	*base;
	int		count;
	char	c;

	base = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16);
	c = base[nb % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printf_hex(va_list *args)
{
	unsigned int	nb;

	nb = va_arg(*args, unsigned int);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_puthex(nb));
}
