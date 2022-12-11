/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:34:27 by soulee            #+#    #+#             */
/*   Updated: 2022/12/11 20:55:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

// REMOVE BEFORE FLIGHT
#include <stdio.h>
// REMOVE BEFORE FLIGHT

int		is_specifier(const char specifier);
void	fmt_parser(const char *fmt, va_list args);
int	ft_print_char(va_list args);
int	ft_print_string(va_list args);
int	ft_print_pointer(va_list args);

typedef struct setting
{
	int	minus;
	int	zero;
	int	hash;
	int	blank;
	int	plus;
}	settings;

#endif