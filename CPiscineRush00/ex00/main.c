/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:15:19 by soulee            #+#    #+#             */
/*   Updated: 2022/08/30 02:29:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(int fd, char *str);
void	rush(int col, int row);

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc == 1)
	{
		rush(5, 3);
		return (0);
	}
	else if (argc == 3)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (y < 0 || x < 0)
		{
			ft_putstr(2, "INVALID_NUMBERS");
			return (1);
		}
	}
	else
	{
		ft_putstr(2, "INVALID_ARGUMENTS");
		return (1);
	}
	rush(x, y);
	return (0);
}
