/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:21:57 by soulee            #+#    #+#             */
/*   Updated: 2023/01/18 19:35:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrap_exit(int exit_code, char *error_message)
{
	if (exit_code == EXIT_SUCCESS)
		exit(0);
	ft_putendl_fd(error_message, 2);
	exit(1);
}
