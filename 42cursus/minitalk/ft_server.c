/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:38:38 by soulee            #+#    #+#             */
/*   Updated: 2023/01/08 19:26:20 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	receive_signal(int sig)
{
	static int	bit_count;
	static char	c;

	if (sig == SIGUSR1)
	{
		c |= 0;
		if (bit_count < 7)
			c <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		c |= 1;
		if (bit_count < 7)
			c <<= 1;
	}
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
}
