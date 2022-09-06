/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/06 17:54:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str);
void	ft_putchr(char c);
void	ft_putstr_to_n_base(int decimal, int n_base, char *base);
int		is_valid_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;
	char	*str;
	int		count;
	int		n_base;
	int		number;

	count = 0;
	number = 0;
	if (is_valid_base(base_from) == 0 || is_valid_base(base_to) == 0)
		return (0);

	while (*nbr != '\0')
	{
		if (*nbr >= '0' && *nbr <= '9')
			number = number * 10 + (*nbr - '0');
		nbr++;
	}

	if (nbr[0] == '-')
		ft_putstr_to_n_base(-number, ft_strlen(base_from), base_from);
	else
		ft_putstr_to_n_base(number, ft_strlen(base_from), base_from);
}

void	main()
{
	ft_convert_base("-23", "0123456789ABCDEF", "ABCDEF");
}