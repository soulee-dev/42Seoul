/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:34:27 by soulee            #+#    #+#             */
/*   Updated: 2022/12/12 20:02:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		is_specifier(const char specifier);
int		fmt_parser(const char *fmt, va_list args);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_percent(void);
int		ft_print_int(va_list args);
int		ft_print_unsigned_int(va_list args);
int		ft_print_hex_lower(va_list args);
int		ft_print_hex_capital(va_list args);
void	ft_putnbr_base(int base, long long nbr, int *count, char *base_text);
void	ft_putnbr_base_unsigned(int base, size_t nbr,
			int *count, char *base_text);
#endif