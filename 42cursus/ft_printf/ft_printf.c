/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:14:04 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 19:53:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(const char specifier, va_list args )
{
	if (specifier == 'c')
		return (ft_print_char(args));
	if (specifier == 's')
		return (ft_print_string(args));
	if (specifier == 'p')
		return (ft_print_pointer(args));
	if (specifier == 'd')
		return (ft_print_int(args));
	if (specifier == 'i')
		return (ft_print_int(args));
	if (specifier == 'u')
		return (ft_print_unsigned_int(args));
	if (specifier == 'x')
		return (ft_print_hex_lower(args));
	if (specifier == 'X')
		return (ft_print_hex_capital(args));
	if (specifier == '%')
		return (ft_print_percent());
	return (-1);
}

int	fmt_parser(const char *fmt, va_list args)
{
	int	flag;
	int	count;
	int	temp;

	count = 0;
	flag = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			flag = 1;
			fmt++;
		}		
		if (flag)
		{
			temp = check_specifier(*fmt, args);
			if (temp > -1)
				flag = 0;
			count += temp;
		}
		else if (*fmt != '%')
			count += ft_putchr(*fmt);
		fmt++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	args;

	va_start(args, fmt);
	count = fmt_parser(fmt, args);
	va_end(args);
	return (count);
}
