/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_integer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:57:43 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 20:04:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args)
{
	int	count;

	count = 0;
	ft_putnbr_base(10, va_arg(args, int), &count, "0123456789");
	return (count);
}

int	ft_print_unsigned_int(va_list args)
{
	int	count;
	int	nbr;

	count = 0;
	nbr = va_arg(args, unsigned int);
	ft_putnbr_base(10, (unsigned int)nbr, &count, "0123456789");
	return (count);
}
