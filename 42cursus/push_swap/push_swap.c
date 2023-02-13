/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/13 21:48:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivots(int	*array, int size, int *max_pivot, int *min_pivot)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[j])
		{
			if (array[i] < array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			j++;
		}
		i++;
	}
	*max_pivot = array[(int)(size * (1.0 / 3.0))];
	*min_pivot = array[(int)(size * (2.0 / 3.0))];
	free(array);
}

void	parition_stack(t_stack *stack)
{
	int		*array;
	int		min_pivot;
	int		max_pivot;

	array = list_to_array(stack);
	get_pivots(array, stack->a_size, &min_pivot, &max_pivot);
	printf("min_pivot: %d\nmax_pivot: %d\n", min_pivot, max_pivot);
	while (stack->a_size > 6)
	{
		printf("curr: %d\n", stack->a_top->content);
		printf("stack a: ");
		iter_node(stack->a_top);
		printf("stack b: ");
		iter_node(stack->b_top);
		if (max_pivot > stack->a_top->content)
			ra(stack);
		else if (max_pivot <= stack->a_top->content && min_pivot >= stack->a_top->content)
			pb(stack);
		else if (min_pivot > stack->a_top->content)
		{
			pb(stack);
			rb(stack);
		}
		printf("stack a: ");
		iter_node(stack->a_top);
		printf("stack b: ");
		iter_node(stack->b_top);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);

	stack = parse_arguments(argv);
	parition_stack(stack);
	return (0);
}
