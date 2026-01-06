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

static int	ft_puthexupper(unsigned int nb)
{
	char	*base;
	int		count;
	char	c;

	base = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_puthexupper(nb / 16);
	c = base[nb % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printf_hexupper(va_list *args)
{
	unsigned int	nb;

	nb = va_arg(*args, unsigned int);
	if (nb == 0)
    {
        write(1, "0", 1);
		return (1);
    }
	return (ft_puthexupper(nb));
}