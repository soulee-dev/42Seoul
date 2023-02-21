/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:53:30 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 21:53:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	wrap_exit(int exit_code, char *error_message)
{
	if (exit_code == EXIT_SUCCESS)
		exit(0);
	ft_putendl_fd(error_message, 2);
	exit(1);
}
