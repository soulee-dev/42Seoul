/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:28:28 by soulee            #+#    #+#             */
/*   Updated: 2023/02/22 17:12:53 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted(t_stack *stack)
{
	int		temp;
	int		count;
	t_node	*node;

	count = 0;
	temp = -2147483648;
	node = stack->a_top;
	while (node)
	{
		if (temp < node->content)
		{
			count++;
			temp = node->content;
		}
		node = node->next;
	}
	if (count == stack->a_size)
		return (1);
	return (0);
}

void	excute_operator(t_stack *stack, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		sa(stack);
	if (!ft_strncmp("sb\n", line, 3))
		sb(stack);
	if (!ft_strncmp("ss\n", line, 3))
		ss(stack);
	if (!ft_strncmp("pa\n", line, 3))
		pa(stack);
	if (!ft_strncmp("pb\n", line, 3))
		pb(stack);
	if (!ft_strncmp("ra\n", line, 3))
		ra(stack);
	if (!ft_strncmp("rb\n", line, 3))
		rb(stack);
	if (!ft_strncmp("rr\n", line, 3))
		rr(stack);
	if (!ft_strncmp("rra\n", line, 3))
		rra(stack);
	if (!ft_strncmp("rrb\n", line, 3))
		rrb(stack);
	if (!ft_strncmp("rrr\n", line, 3))
		rrr(stack);
}

int	main(int argc, char *argv[])
{
	char	*line;
	t_stack	*stack;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);
	stack = parse_arguments(argv);
	line = get_next_line(0);
	while (line)
	{
		excute_operator(stack, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stack);
	return (0);
}
