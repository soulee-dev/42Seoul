/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:43:10 by soulee            #+#    #+#             */
/*   Updated: 2023/02/14 16:07:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// ---- REMOVE BEFORE FLIGHT ----
# include <stdio.h>
// ---- REMOVE BEFORE FLIGHT ----
# include "../libft/libft.h"
# include <stdlib.h>
# define EXIT_SUCCESS 0
# define EXIT_ERROR 1

typedef struct s_node {
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*a_top;
	t_node	*a_bot;
	int		a_size;
	t_node	*b_top;
	t_node	*b_bot;
	int		b_size;
}	t_stack;

void	wrap_exit(int exit_code, char *error_message);

void	wrap_atoi(t_node **node, const char *str);
t_stack	*parse_arguments(char **arguments);
int		*list_to_array(t_stack *stack);

t_node	*create_new_node(int content);
void	add_node_back(t_node **node, t_node *new);
void	iter_node(t_node *node);
t_stack	*init_stack(t_node *list_a);
t_node	*get_last_node(t_node *node);
int		get_list_size(t_node *node);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
#endif