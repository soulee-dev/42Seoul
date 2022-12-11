/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:14:04 by soulee            #+#    #+#             */
/*   Updated: 2022/12/11 20:59:52 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(const char specifier, va_list args )
{
	if (specifier == 'c')
		return(ft_print_char(args));
		
	if (specifier == 's')
	{
		return(ft_print_string(args));
	}

	if (specifier == 'p')
	{
		return(ft_print_pointer(args));
	}

	if (specifier == 'd')
	{
		printf("%d", va_arg(args, int));
		return (1);
	}
		
	if (specifier == 'i')
	{
		return(ft_print)
	}

	// if (specifier == 'u')
	// {

	// }

	// if (specifier == 'x')
	// {

	// }

	// if (specifier == 'X')
	// {

	// }

	// if (specifier == '%')
	// {

	// }
	return (0);
}

void	fmt_parser(const char *fmt, va_list args) {
	int	flag;

	flag = 0;
	while (*fmt) {
		if (*fmt == '%')
			flag = 1;
		if (flag)
			if (check_specifier(*fmt, args))
				flag = 0;
		fmt++;
	}
}


int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);

	fmt_parser(fmt, args);

	va_end(args);
	return (0);
}

int	main() {
	char *str = "AASA";
	
	ft_printf("%p", str);

	return (0);
}
