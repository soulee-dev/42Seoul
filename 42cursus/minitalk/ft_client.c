/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:37:20 by soulee            #+#    #+#             */
/*   Updated: 2022/12/19 18:19:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

void	send_signal(pid_t pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		c = *str;
		i = 8;
		while (--i >= 0)
		{
			if (c & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	client_pid;
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("INVALID ARGUMENT", 1);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 100 || server_pid >= 99999)
	{
		ft_putstr_fd("INVALID PID", 1);
		exit(1);
	}
	send_signal(server_pid, argv[2]);
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	client_pid = getpid();
	ft_putstr_fd("client pid: ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putchar_fd('\n', 1);
}
