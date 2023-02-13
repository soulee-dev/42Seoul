/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:18 by soulee            #+#    #+#             */
/*   Updated: 2023/02/13 15:23:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(int a)
{
	printf("%d\n", a);
}

int	main(int argc, char *argv[])
{
	t_node	*list_a;
	t_stack	*stack;
	int	i;
	char	**splitted_data;

	if (argc < 2)
		wrap_exit(EXIT_SUCCESS, 0);
	i = 1;
	while (argv[i])
	{
		splitted_data = ft_split(argv[i], ' ');
		while (*splitted_data)
		{
			wrap_atoi(&list_a, *splitted_data);
			splitted_data++;
		}
		i++;
	}
	stack = init_stack(list_a);
	printf("a: \n");
	iter_node(stack->a_top, print_int);
	
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	printf("pb: \n");
	iter_node(stack->b_top, print_int);

	// Segfault 발생
	printf("rb: \n");
	rb(stack);
	iter_node(stack->b_top, print_int);
	return (0);
}
