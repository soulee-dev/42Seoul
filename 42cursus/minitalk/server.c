/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:38:38 by soulee            #+#    #+#             */
/*   Updated: 2022/12/17 23:10:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

void	receive_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("0");
	else if (sig == SIGUSR2)
		ft_printf("1");
}

int	main()
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("server pid: %d\n", server_pid);

	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
}