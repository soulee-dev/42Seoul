#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
// REMOVE BEFORE FLIGHT
# include <stdio.h>
// REMOVE BEFORE FLIGHT

int		is_specifier(const char specifier);
void	fmt_parser(const char *fmt);

typedef struct setting
{
	int	minus;
	int	zero;
	int	hash;
	int	blank;
	int	plus;
}	settings;

#endif