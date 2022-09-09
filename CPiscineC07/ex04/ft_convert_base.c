/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/09 03:40:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_valid_base(char *base);
int		ft_ft_strlen(char *str);
int		ft_find_str(char *str, char c);
char	*ft_remove_sign(char *str, int *sign);
void	ft_putstr_to_n_base(char *str, int decimal, int n_base, char *base);

int	ft_atoi_base(char *str, char *base)
{
	long long	n_base;
	long long	n;
	long long	i;
	int			sign;

	i = 0;
	n = 0;
	n_base = ft_ft_strlen(base);
	str = ft_remove_sign(str, &sign);
	while (*str)
	{
		if (ft_find_str(base, str[i]) >= 0)
			n = (n * n_base) + ft_find_str(base, str[i]);
		else
			break ;
		str++;
	}
	return ((int)(n * sign));
}

void	ft_putnbr_base(char *str, int nbr, char *base)
{
	int	n_base;

	if (is_valid_base(base) == 0)
		return ;
	n_base = ft_ft_strlen(base);
	if (nbr == -2147483648)
	{
		str[1] = '-';
		ft_putstr_to_n_base(str, -(nbr / n_base), n_base, base);
		str[(int)(str[0]++)] = base[nbr % n_base * -1];
		return ;
	}
	if (nbr < 0)
	{
		str[1] = '-';
		nbr = -nbr;
	}
	ft_putstr_to_n_base(str, nbr, n_base, base);
}

char	*siballoc(int decimal, int n_base)
{
	int		size;
	char	*str;

	size = 0;
	while (1)
	{
		size++;
		decimal /= n_base;
		if (decimal == 0)
			break ;
	}
	str = malloc(sizeof(char) * size + 2);
	str[0] = 2;
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		result_atoi_base;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	result_atoi_base = ft_atoi_base(nbr, base_from);
	if (!result_atoi_base)
		return ("\0");
	str = siballoc(result_atoi_base, ft_ft_strlen(base_to));
	if (!str || !result_atoi_base)
		return ("\0");
	ft_putnbr_base(str, result_atoi_base, base_to);
	str++;
	if (!(str[0] == '-'))
		str++;
	return (str);
}
