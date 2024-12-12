/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:11:22 by nacao             #+#    #+#             */
/*   Updated: 2024/12/12 13:55:42 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	before_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	if (!stack || !top_node)
		return ;
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	move_a_to_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(a);
	if (cheapest_node->above_median)
	{
		rr(a, b, true);
		current_index(a);
		current_index(b);
	}
	else
	{
		rrr(a, b, true);
		current_index(a);
		current_index(b);
	}
	before_push(a, cheapest_node, a);
	before_push(b, cheapest_node->target_node, b);
	pb(a, b, true);
}
