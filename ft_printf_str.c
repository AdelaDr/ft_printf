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

int	ft_printf_str(va_list *args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(*args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}
