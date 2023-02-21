/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:50:32 by soulee            #+#    #+#             */
/*   Updated: 2023/02/21 23:00:53 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*create_new_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	get_list_size(t_node *node)
{
	int	count;

	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_node	*get_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	check_duplicated(t_node *node, int val)
{
	while (node)
	{
		if (node->content == val)
			return (1);
		node = node->next;
	}
	return (0);
}

void	add_node_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!*node)
	{
		*node = new;
		return ;
	}
	if (check_duplicated(*node, new->content))
		wrap_exit(EXIT_ERROR, "Error");
	last = get_last_node(*node);
	last->next = new;
}
