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

static int ft_putnbr_uns(unsigned int nb)
{
	char	a;
    int count;

    count = 0;
	if (nb >= 10)
        count += ft_putnbr_uns(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
    count++;
    return(count);
}

int	ft_printf_unsigned(va_list *args)
{
	unsigned int	nb;

	nb = va_arg(*args, unsigned int);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_putnbr_uns(nb));
}