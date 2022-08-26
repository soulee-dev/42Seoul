/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:36:22 by soulee            #+#    #+#             */
/*   Updated: 2022/08/26 21:45:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_to_hex(int decimal)
{
	char	hex[3]
	int		mod;
	int		i;

	i = 0;
	mod = decimal % 16 < 10;
	if (modulo < 10)
		hex[i] = mod + '0';
	else
		hex[i] = (mod - 10) + 'a';
	decimal /= 16;
	i++;
	if (decimal == 0)
		break ;
}


void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if(str[i] >= 0 && str[i <= 31])
		{

		}
		printf("%02x ",str[i]);
		i++;
	}
}