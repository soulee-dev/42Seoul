/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:11 by soulee            #+#    #+#             */
/*   Updated: 2022/09/13 01:22:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // REMOVE BEFORE FLIGHT

int		ft_ft_strlen(char *str);
int		ft_is_valid_base(char *base);
int		ft_find_str(char *str, char c);
char	*ft_remove_sign(char *str, int *sign);

int	ft_atoi_base(char *str, char *base)
{
	long long	n_base;
	long long	n;
	long long	i;
	int			sign;

	i = 0;
	n = 0;
	if (ft_is_valid_base(base) == 0)
		return (0);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	
}

int	main(void)
{
	ft_convert_base("1234", "0123456789", "0123456789");
}