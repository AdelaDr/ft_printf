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

static int type_parser(char type, va_list *args)
{
    if (type == 'c')
        return (ft_printf_char(args));
    if (type == 's')
        return (ft_printf_str(args));
    if (type == 'p')
        //return (ft_printf_p(args));
    if (type == 'd' || type == 'i')
        return (ft_printf_int(args));
    if (type == 'u')
        return (ft_printf_unsigned(args));
    if (type == 'x')
        return (ft_printf_hex(args));
    if (type == 'X')
        return (ft_printf_hexupper(args));
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    
    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else 
                if (*format)
                    count += type_parser(*format, &args);
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return (count);
}
