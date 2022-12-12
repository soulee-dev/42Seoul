/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:59:28 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 20:04:08 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	ft_putchr(va_arg(args, int));
	return (1);
}

int	ft_print_string(va_list args)
{
	int		count;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = ft_putstr(str);
	return (count);
}
