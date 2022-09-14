/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 19:45:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // REMOVE BEFORE FLIGHT

int		ft_ft_strlen(char *str);
int		ft_is_valid_base(char *base);
int		ft_find_str(char *str, char c);
char	*ft_remove_sign(char *str, long long *sign);

int	ft_atoi_base(char *str, char *base)
{
	long long	n_base;
	long long	n;
	long long	i;
	long long	sign;

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

int	ft_putstr_to_n_base(int idx, char *result_str, int decimal, char *base)
{
	long long	nbr;
	long long	n_base;

	n_base = ft_ft_strlen(base);
	if (decimal < 0)
	{
		printf("a:%d\n", idx);
		result_str[idx++] = '-';
		nbr = -decimal;
	}
	else
		nbr = decimal;
	if (nbr >= n_base)
		ft_putstr_to_n_base(idx - 1, result_str, nbr / n_base, base);
	printf("b:%d\n", idx);
	result_str[idx] = base[nbr % n_base];
	return (idx);
}

int	get_size(int decimal, int n_base)
{
	int	size;

	size = 0;
	while (decimal >= n_base)
	{
		++size;
		decimal /= n_base;
	}
	return (size + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		idx;
	char	*str;
	int		result_atoi_base;

	if (!nbr || !base_to || !base_from)
		return (NULL);
	if (ft_ft_strlen(nbr) == 0)
		return (NULL);
	if (ft_is_valid_base(base_from) == 0 || ft_is_valid_base(base_to) == 0)
		return (NULL);
	result_atoi_base = ft_atoi_base(nbr, base_from);
	str = malloc(sizeof(char) * get_size(result_atoi_base,
				ft_ft_strlen(base_to)));
	idx = ft_putstr_to_n_base(get_size(result_atoi_base, ft_ft_strlen(base_to)) + 1, str, result_atoi_base, base_to);
	str[idx + 1] = '\0';
	return (str);
}

int	main(void)
{
	printf("%s", ft_convert_base("-10000", "0123456789", "0123456789"));
}