/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:58:24 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 20:04:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(va_list args)
{
	int	count;

	count = 0;
	ft_putnbr_base(16, va_arg(args, unsigned int), &count, "0123456789abcdef");
	return (count);
}

int	ft_print_hex_capital(va_list args)
{
	int	count;

	count = 0;
	ft_putnbr_base(16, va_arg(args, unsigned int), &count, "0123456789ABCDEF");
	return (count);
}

int	ft_print_pointer(va_list args)
{
	int		count;
	size_t	ptr;

	count = 0;
	ptr = va_arg(args, size_t);
	ft_putstr("0x");
	count += 2;
	ft_putnbr_base_unsigned(16, ptr, &count, "0123456789abcdef");
	return (count);
}
