/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:16:51 by soulee            #+#    #+#             */
/*   Updated: 2022/09/15 03:18:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_check(char *base, char c);
int		ft_base_len(char *base);
char	*ft_itoa(long long base_len2, long long re, char *base_to);
char	*ft_final(int size, long long re, char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[0] == 0 || base[1] == 0)
			return (0);
		else if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i;
		while (base[j])
		{
			j++;
			if (base[i] == base[j])
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi_check(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*remove_spaces(char *str, int *m)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*m = *m * (-1);
		i++;
	}
	return (&str[i]);
}

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}
