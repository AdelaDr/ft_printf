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

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

static int	ft_puthex(unsigned long nb)
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

int ft_printf_address(va_list *args)
{
    unsigned long address;
    int count;

    address = va_arg(*args, unsigned long);
    write(1, "0x", 2);
    count = 2;
    count += ft_puthex(address);
    return (count);
}