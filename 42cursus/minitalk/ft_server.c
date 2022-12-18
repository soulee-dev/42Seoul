/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:38:38 by soulee            #+#    #+#             */
/*   Updated: 2022/12/18 17:56:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf.h"

void	receive_signal(int sig)
{
	static int	bit_count = 8;
	static char c = 0;

	if (sig == SIGUSR1)
		c += 1 << --bit_count;
	else if (sig == SIGUSR2)
		bit_count--;
	
	if (bit_count == 0)
	{
		ft_printf("%c\n", c);
		bit_count = 8;
		c = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("server pid: %d\n", server_pid);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
}
