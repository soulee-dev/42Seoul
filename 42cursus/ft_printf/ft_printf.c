/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:14:04 by soulee            #+#    #+#             */
/*   Updated: 2022/11/18 00:29:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

settings	is_specifier(const char specifier) {
	if (specifier == 'c')
		
	if (specifier == 's')

	if (specifier == 'p')

	if (specifier == 'd')

	if (specifier == 'i')

	if (specifier == 'u')

	if (specifier == 'x')

	if (specifier == 'X')

	if (specifier == '%')
}

void	fmt_parser(const char *fmt) {
	int	flag;

	flag = 0;
	while (*fmt) {
		if (*fmt == '%')
			flag = 1;
		if (flag && is_specifier(*fmt))
		fmt++;
	}

	printf("%d", flag);	
}


int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);

	fmt_parser(fmt);

	// return the number of character printed
}

int	main() {
	// ft_printf("%d", 100);
	printf("%+0100d", 100);

	return (0);
}