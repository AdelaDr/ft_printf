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

static int	ft_putnbr(int nb)
{
	char	a;
    int count;

    count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
        count++;
	}
	if (nb >= 10)
        count += ft_putnbr(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
    count++;
    return(count);
}

int ft_printf_int(va_list *args)
{
    int nb;

    nb = ft_putnbr(va_arg(*args,int));
    return (nb);
}
