/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:53:30 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 22:51:21 by soulee           ###   ########.fr       */
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

void	free_all(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->a_top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	node = stack->b_top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
	stack = 0;
}

void	free_split(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
